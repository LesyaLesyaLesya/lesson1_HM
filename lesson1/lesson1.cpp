﻿// lesson1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*--------------------------------------------------
    Имеется база сотрудников и номеров их телефонов. 
    Требуется написать соответствующие структуры для хранения данных, и заполнить контейнер записями из базы.
    Затем необходимо реализовать методы обработки данных, а также вывести на экран всю необходимую информацию.
Важно! Имена переменным, классам и функциям давайте осознанные, состоящие из слов на английском языке.
    +1.  Создайте структуру Person с 3 полями: фамилия, имя, отчество. 
    Поле отчество должно быть опционального типа, т.к. не у всех людей есть отчество. 
    Перегрузите оператор вывода данных для этой структуры. 
    Также перегрузите операторы < и == (используйте tie).

    2.  Создайте структуру PhoneNumber с 4 полями:
·         код страны (целое число)
·         код города (целое число)
·         номер (строка)
·         добавочный номер (целое число, опциональный тип)
    Для этой структуры перегрузите оператор вывода.  
    Необходимо, чтобы номер телефона выводился в формате: +7(911)1234567 12, где 7 – это номер страны, 911 – номер города, 
    1234567 – номер, 12 – добавочный номер. Если добавочного номера нет, то его выводить не надо.
    Также перегрузите операторы < и == (используйте tie)

    3.  Создайте класс PhoneBook, который будет в контейнере хранить пары: Человек – Номер телефона. 
    Конструктор этого класса должен принимать параметр типа ifstream – поток данных, полученных из файла. 
    В теле конструктора происходит считывание данных из файла и заполнение контейнера. 
    Класс PhoneBook должен содержать перегруженный оператор вывода, для вывода всех данных из контейнера в консоль.

    В классе PhoneBook реализуйте метод SortByName, который должен сортировать элементы контейнера по фамилии людей в алфавитном порядке.
    Если фамилии будут одинаковыми, то сортировка должна выполняться по именам, если имена будут одинаковы, 
    то сортировка производится по отчествам. Используйте алгоритмическую функцию sort.

    Реализуйте метод SortByPhone, который должен сортировать элементы контейнера по номерам телефонов.
    Используйте алгоритмическую функцию sort.

    Реализуйте метод GetPhoneNumber, который принимает фамилию человека, а возвращает кортеж из строки и PhoneNumber. 
    Строка должна быть пустой, если найден ровно один человек с заданном фамилией в списке. 
    Если не найден ни один человек с заданной фамилией, то в строке должна быть запись «not found»,
    если было найдено больше одного человека, то в строке должно быть «found more than 1». 

    Реализуйте метод ChangePhoneNumber, который принимает человека и новый номер телефона и, 
    если находит заданного человека в контейнере, то меняет его номер телефона на новый, иначе ничего не делает. 

    ----------------------------------------------------*/
#include <iostream>
#include <optional>
#include <tuple>

using namespace std;

struct Person
{
    
    string _name;
    string _surname;
    optional<string> _patronymic;

};
struct PhoneNumber
{
    int             countryCode;
    int             cityCode;
    string          number;
    optional<int>   extension;

};

ostream& operator<< (ostream& out, const Person& person)
{
    out << person._surname << " " << person._name <<  " " << (person._patronymic.has_value() ? *person._patronymic : "");
    return out;
}

bool operator< (const Person& person1, const Person& person2)
{
    return tie(person1._surname, person1._name, (person1._patronymic.has_value() ? *person1._patronymic : ""))
        < tie(person2._surname, person1._name, (person2._patronymic.has_value() ? *person2._patronymic : ""));
}

bool operator== (const Person& person1, const Person& person2)
{
    return tie(person1._surname, person1._name, (person1._patronymic.has_value() ? *person1._patronymic : ""))
        == tie(person2._surname, person1._name, (person2._patronymic.has_value() ? *person2._patronymic : ""));
}



/*Для этой структуры перегрузите оператор вывода.
Необходимо, чтобы номер телефона выводился в формате : +7(911)1234567 12, где 7 – это номер страны, 911 – номер города,
1234567 – номер, 12 – добавочный номер.Если добавочного номера нет, то его выводить не надо.
Также перегрузите операторы < и == (используйте tie)*/
    ostream& operator<< (ostream& out, const PhoneNumber& number)
{
    out << "+" << number.countryCode << "(" << number.cityCode << ")" << number.number ;
    if (number.extension.has_value())
    {
        out << " " << number.extension.value();

    }
    return out;
}

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

int main()
{
    Person p = {"Lesya", "Sidorova"};

    cout << p;
    /*
    ifstream file("ХХХ"); // путь к файлу PhoneBook.txt
    PhoneBook book(file);
    cout << book;

    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;

    cout << "-----GetPhoneNumber-----" << endl;
    // лямбда функция, которая принимает фамилию и выводит номер телефона этого    	человека, либо строку с ошибкой
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
        if (get<0>(answer).empty())
            cout << get<1>(answer);
        else
            cout << get<0>(answer);
        cout << endl;
    };

    // вызовы лямбды
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });
    cout << book;*/
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
