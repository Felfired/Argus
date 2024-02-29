#ifndef LATINLETTERVALIDATOR_H
#define LATINLETTERVALIDATOR_H

#include <QValidator>
#include <QChar>

class LatinLetterValidator : public QValidator
{
public:
    State validate(QString& input, int& pos) const override;
};

#endif // LATINLETTERVALIDATOR_H