#pragma once
#include <string>
#include <optional>
#include <iostream>

using namespace std;

struct PhoneNumber
{
    int             countryCode;
    int             cityCode;
    string          number;
    optional<int>   extension;
public:
    PhoneNumber(int m_countryCode, int m_cityCode, string m_number, optional<int> m_extension) :countryCode(m_countryCode), cityCode(m_cityCode), number(m_number), extension(m_extension) {};
    PhoneNumber(const PhoneNumber& phoneNumberForCopy)
    {
        countryCode = phoneNumberForCopy.countryCode;
        cityCode = phoneNumberForCopy.cityCode;
        number = phoneNumberForCopy.number;
        extension = phoneNumberForCopy.extension;
    };
    ~PhoneNumber() = default;
};

bool operator< (const PhoneNumber& number1, const PhoneNumber& number2) ;

bool operator== (const PhoneNumber& number1, const PhoneNumber& number2) ;

ostream& operator<< (ostream& out, const PhoneNumber& number) ;