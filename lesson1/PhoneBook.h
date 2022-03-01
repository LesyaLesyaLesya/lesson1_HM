#pragma once
#include "PhoneNumber.h"
#include "Person.h"
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <tuple>

class PhoneBook
{
private:

    vector<pair<Person, PhoneNumber>> PhoneList;

public:
    PhoneBook(ifstream& file);
    ~PhoneBook() {};

    friend ostream& operator<< (ostream& out, const PhoneBook& PhoneBookForPrint);
    void SortByName();
    void SortByPhone();
    tuple<string, PhoneNumber> GetPhoneNumber(const string& surnameForSearch);
    void ChangePhoneNumber(Person personForSearch, const PhoneNumber& newNumber);
};


