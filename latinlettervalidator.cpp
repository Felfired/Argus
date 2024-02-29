#include "latinlettervalidator.h"

QValidator::State LatinLetterValidator::validate(QString& input, int& pos) const
{
    Q_UNUSED(pos);
    for (const QChar& ch : input) {
        if (!ch.isLetter() || !ch.isPrint()) 
        {
            return Invalid;
        }
        // Check if the character is not a Latin letter (A-Z, a-z).
        if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) 
        {
            return Invalid;
        }
    }
    return Acceptable;
}