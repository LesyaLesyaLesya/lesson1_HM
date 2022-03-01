#pragma once
#include <string>
#include <optional>
#include <iostream>

using namespace std;

struct Person
{

    string _name;
    string _surname;
    optional<string> _patronymic;
public:
    Person(string name, string surname, optional<string> patronymic) : _name(name), _surname(surname), _patronymic(patronymic) {};
};

bool operator< (const Person& person1, const Person& person2) ;

bool operator== (const Person& person1, const Person& person2);

ostream& operator<< (ostream& out, const Person& person);