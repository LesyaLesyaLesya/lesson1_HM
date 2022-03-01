
#include "PhoneNumber.h"

bool operator< (const PhoneNumber& number1, const PhoneNumber& number2)
{
    return tie(number1.countryCode, number1.cityCode, number1.number)
        < tie(number2.countryCode, number2.cityCode, number2.number);
}

bool operator== (const PhoneNumber& number1, const PhoneNumber& number2)
{
    return tie(number1.countryCode, number1.cityCode, number1.number)
        == tie(number2.countryCode, number2.cityCode, number2.number);
}

ostream& operator<< (ostream& out, const PhoneNumber& number)
{
    out << "+" << number.countryCode << "(" << number.cityCode << ")" << number.number;
    if (!(number.extension == 0) && !(number.extension == nullopt))
    {

        out << " " << number.extension.value();

    }

    return out;
}