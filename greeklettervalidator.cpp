#include "greeklettervalidator.h"

QValidator::State GreekLetterValidator::validate(QString& input, int& pos) const 
{
    Q_UNUSED(pos);
    for (const QChar& ch : input) 
    {
        // Ensure it's a printable letter.
        if (!ch.isLetter() || !ch.isPrint()) 
        { 
            return Invalid;
        }

        // Range for Greek letters.
        if (ch.unicode() < 0x0370 || ch.unicode() > 0x03FF) 
        { 
            return Invalid;
        }
    }
    return Acceptable;
}