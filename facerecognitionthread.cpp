#include "facerecognitionthread.h"
#include "facerecognition.h"

FaceRecognitionThread::FaceRecognitionThread(const QString& folderPath,
											 const QString& distanceCalculationMode,
											 QObject* parent)
											 : QThread(parent),
											 folderPath(folderPath),
											 distanceCalculationMode(distanceCalculationMode)

{
	QSettings settings("config.ini", QSettings::IniFormat);
	indexPath = settings.value("Recognition_Preferences/Index_Path").toString();
	modelPath = settings.value("Recognition_Preferences/SFace_Path").toString();
	thresholdCosine = 0.363;
	thresholdEuclidean = 1.128;
}

FaceRecognitionThread::~FaceRecognitionThread()
{
	// Destructor currently does not need implementation.
}

void FaceRecognitionThread::run()
{
	returnCode = FaceRecognitionThread::initializeRecognition();
	
	if (returnCode == 0)
	{
		emit onThreadQuitRequested();
		quit();
	}
}

void FaceRecognitionThread::threadQuit()
{
	emit onThreadQuitRequested();
	quit();
}

int FaceRecognitionThread::initializeRecognition()
{
	int returnCodeDNN = FaceRecognitionThread::initializeSFaceDNN();
	if (returnCodeDNN == 0)
	{
		FaceRecognitionThread::recognitionScan();
	}
	else
	{
		QMessageBox::critical(nullptr, tr("Σφάλμα"), tr("Άποτυχία φόρτωσης του νευρωνικού δικτύου."));
		return 1;
	}
	return 0;
}

int FaceRecognitionThread::initializeSFaceDNN()
{
	std::string modelPathString = modelPath.toStdString();
	sfaceDNN = cv::FaceRecognizerSF::create(modelPathString, 
											"", 
											cv::dnn::Backend::DNN_BACKEND_OPENCV, 
											cv::dnn::DNN_TARGET_CPU);
	return 0;
}

cv::Mat FaceRecognitionThread::imageInference(cv::Mat inputImage)
{
	cv::Mat features;
	sfaceDNN->feature(inputImage, features);
	features = features.clone();
	return features;
}

int FaceRecognitionThread::matchImages(cv::Mat unknownFeatures, cv::Mat referenceFetures)
{
	if (distanceCalculationMode == "Συνημιτόνου")
	{
		double cosineScore = sfaceDNN->match(unknownFeatures, 
											 referenceFetures, 
											 cv::FaceRecognizerSF::DisType::FR_COSINE);
		if (cosineScore >= thresholdCosine)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	else if (distanceCalculationMode == "Ευκλείδιος")
	{
		double euclideanScore = sfaceDNN->match(unknownFeatures,
												referenceFetures,
												cv::FaceRecognizerSF::DisType::FR_NORM_L2);
		if (euclideanScore <= thresholdEuclidean)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void FaceRecognitionThread::recognitionScan()
{
	int processedImages = 0;
	QStringList jpgFiles;
	std::vector<std::vector<std::string>> indexVector;
	indexVector = FaceRecognitionThread::createIndexVector();
	jpgFiles = FaceRecognitionThread::getImagePathsFromDirectory();
	int totalImages = jpgFiles.size();
	foreach (QString fileName, jpgFiles)
	{
		processedImages++;
		QString filePath = folderPath + "/" + fileName;
		std::string filePathString = filePath.toStdString();
		cv::Mat unknownImage = cv::imread(filePathString);
		cv::Mat unknownFeatures = FaceRecognitionThread::imageInference(unknownImage);

		for (const auto& indexEntry : indexVector)
		{
			if (indexEntry.size() >= 2)
			{
				const std::string& path = indexEntry[0];
				const std::string& id = indexEntry[1];

				cv::Mat referenceImage = cv::imread(path);
				cv::Mat referenceFeatures = FaceRecognitionThread::imageInference(referenceImage);

				int result = FaceRecognitionThread::matchImages(unknownFeatures, referenceFeatures);
				if (result == 0)
				{
					auto checkDuplicate = std::find(duplicateRecognitions.begin(),
										            duplicateRecognitions.end(),
													path);
					if (checkDuplicate != duplicateRecognitions.end())
					{
						// Do nothing.
					}
					else
					{
						emit postRecognitionID(id);
						emit postRecognitionPath(path);
						qDebug() << "detected";
						duplicateRecognitions.push_back(path);
					}
				}
			}
		}
		int progress = static_cast<int>((processedImages / static_cast<double>(totalImages)) * 100);
		emit setLoadingProgress(progress);
	}
}

QStringList FaceRecognitionThread::getImagePathsFromDirectory()
{
	QDir directory(folderPath);
	QStringList filters; 
	filters << "*.jpg";
	directory.setNameFilters(filters);
	QStringList jpgFiles = directory.entryList();
	return jpgFiles;
}

std::vector<std::vector<std::string>> FaceRecognitionThread::createIndexVector()
{
	std::vector<std::vector<std::string>> indexVector;
	std::string indexPathString = indexPath.toStdString();

	// Open the file.
	std::ifstream indexFile(indexPathString);
	if (!indexFile.is_open())
	{
		return indexVector;
	}

	std::string line;
	// Read each line from the file.
	while (std::getline(indexFile, line)) 
	{
		std::istringstream iss(line);
		std::vector<std::string> pathAndId;
		std::string path, id;

		// Split the line by space.
		if (!(iss >> path >> id)) 
		{
			std::cerr << "Invalid line format: " << line << std::endl;
			continue;
		}
		pathAndId.push_back(path);
		pathAndId.push_back(id);

		// Add path and id to the vector.
		indexVector.push_back(pathAndId);
	}

	// Close the file.
	indexFile.close();

	return indexVector;
}