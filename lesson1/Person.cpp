#include "Person.h"

bool operator< (const Person& person1, const Person& person2)
{
    return tie(person1._surname, person1._name, (person1._patronymic.has_value() ? *person1._patronymic : ""))
        < tie(person2._surname, person1._name, (person2._patronymic.has_value() ? *person2._patronymic : ""));
}

bool operator== (const Person& person1, const Person& person2)
{
    return tie(person1._surname, person1._name, person1._patronymic)
        == tie(person2._surname, person1._name, person2._patronymic);
}

ostream& operator<< (ostream& out, const Person& person)
{
    //выравнивающие строки

    string addName(16 - person._name.length(), ' ');
    string addSurname(16 - person._surname.length(), ' ');
    string addPatronymic(16 - person._patronymic.value().length(), ' ');

    //вывод
    out << addSurname << person._surname << addName << person._name << addPatronymic << (person._patronymic.has_value() ? *person._patronymic : "");
    return out;
}