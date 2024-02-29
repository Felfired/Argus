#ifndef GREEKLETTERVALIDATOR_H
#define GREEKLETTERVALIDATOR_H

#include <QValidator>
#include <QChar>

class GreekLetterValidator : public QValidator 
{
public:
    State validate(QString& input, int& pos) const override;
};

#endif // GREEKLETTERVALIDATOR_H

