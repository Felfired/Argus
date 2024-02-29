#include "extractframesdialog.h"

ExtractFramesDialog::ExtractFramesDialog(QWidget *parent)
    : QDialog(parent)
{
    mainLayout = new QVBoxLayout(this);
    frameskipLayout = new QHBoxLayout();

    frameskipSpinBox = new QSpinBox();
    frameskipSpinBox->setRange(0, 1000);
    frameskipSpinBox->setValue(0);
    frameskipSpinBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    frameskipLabel = new QLabel("Αριθμός Παράλειψης Καρέ (0-1000): ");

    frameskipLayout->addWidget(frameskipLabel);
    frameskipLayout->addWidget(frameskipSpinBox);
    mainLayout->addLayout(frameskipLayout);

    buttonLayout = new QHBoxLayout();
    okButton = new QPushButton("Εκκίνηση");
    closeButton = new QPushButton("Κλείσιμο");

    buttonLayout->addWidget(closeButton);
    buttonLayout->addWidget(okButton);
    mainLayout->addLayout(buttonLayout);

    mainLayout->addStretch(1);

    setWindowTitle(tr("Παραμετροποίηση Εξαγωγής Καρέ"));
    setFixedSize(400, 250);
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    connect(closeButton, &QPushButton::clicked, this, &ExtractFramesDialog::reject);
}
