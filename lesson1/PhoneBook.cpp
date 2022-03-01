#include "PhoneBook.h"

PhoneBook::PhoneBook(ifstream& file)
{
    //ifstream file;

    //file.open();
    char buff[256];
    char* context;

    if (file.is_open())
    {
        while (file.getline(buff, 256))
        {
            vector<const char*> v;
            char* ptr = strtok_s(buff, " ", &context);
            while (ptr)
            {

                //cout << ptr << endl;
                v.push_back(ptr);
                ptr = strtok_s(NULL, " ", &context);
            }

            Person tempPerson = { v.at(1), v.at(0), (v.at(2) == "-") ? "" : optional<string>(v.at(2)) };
            PhoneNumber tempPhoneNumber = { atoi(v.at(3)), atoi(v.at(4)), v.at(5), (v.at(6) == "-") ? nullopt : optional<int>(atoi(v.at(6))) };

            PhoneList.push_back(make_pair(move(tempPerson), move(tempPhoneNumber)));

            delete ptr;

        }
    }

}
void PhoneBook::SortByName()
{
    sort(PhoneList.begin(), PhoneList.end(), [](pair<Person, PhoneNumber> phone1, pair<Person, PhoneNumber> phone2)
        {return phone1.first._surname < phone2.first._surname; });

}
void PhoneBook::SortByPhone()
{
    sort(PhoneList.begin(), PhoneList.end(), [](pair<Person, PhoneNumber> phone1, pair<Person, PhoneNumber> phone2)
        {return phone1.second.number < phone2.second.number; });

}
tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(const string& surnameForSearch)
{
    int count{ 0 };
    PhoneNumber currNum{ 0,0,"",nullopt };
    string emptyString{ "" };

    for (const auto& [person, phoneNumber] : PhoneList)
    {
        if (person._surname == surnameForSearch)
        {
            count++;
            currNum = phoneNumber;
        }
    }

    if (count == 1) { return tie(emptyString, currNum); }
    if (count == 0) { return tie("not found", currNum); }
    if (count > 1) { return tie("found more than 1", currNum); }
}
/*Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и,
если находит заданного человека в контейнере, то меняет его номер телефона на новый, иначе ничего не делает.*/
void PhoneBook::ChangePhoneNumber(Person personForSearch, const PhoneNumber& newNumber)
{
    for (auto& [person, phoneNumber] : PhoneList)
    {
        if (person == personForSearch)
        {
            phoneNumber.cityCode = newNumber.cityCode;
            phoneNumber.countryCode = newNumber.countryCode;
            phoneNumber.extension = newNumber.extension;
            phoneNumber.number = newNumber.number;
        }
    }
}
ostream& operator<< (ostream& out, const PhoneBook& PhoneBookForPrint)
{
    for (const auto& [person, phoneNumber] : PhoneBookForPrint.PhoneList)
    {
        out << person << " " << phoneNumber << endl;
    }

    return out;
}