﻿#include <iostream>
#include <vector>
using namespace std;


struct User
{
    string firstName, lastName;
    int age;
    bool isStudent;
};


User inputUser() {
    User user;

    cout << "Введіть ім'я: ";
    cin >> user.firstName;

    cout << "Введіть прізвище: ";
    cin >> user.lastName;


    while (true) {
        cout << "Введіть вік: ";
        cin >> user.age;

        // Перевірка, чи введено ціле число
        if (cin.fail()) {
            cout << "Помилка: введіть ціле число.\n";
            cin.clear(); // Скидаємо стан помилки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ігноруємо залишки вводу
        }
        else if (user.age < 0) {
            cout << "Помилка: вік не може бути від'ємним.\n";
        }
        else {
            break; // Вихід з циклу, якщо ввід коректний
        }
    }

    char isStudentChar;

    while (true) {
        cout << "Чи є користувач студентом? (y/n): ";
        cin >> isStudentChar;

        if (isStudentChar == 'y' || isStudentChar == 'Y') {
            user.isStudent = true;
            break;
        }
        else if (isStudentChar == 'n' || isStudentChar == 'N') {
            user.isStudent = false;
            break;
        }
        else {
            cout << "Лише 'y' або 'n'! Будь ласка, спробуйте ще раз.\n";
        }
    }

    return user;
}

void displayUser(const User& user) {
    cout << "Ім'я: " << user.firstName << endl;
    cout << "Прізвище: " << user.lastName << endl;
    cout << "Вік людини: " << user.age << endl;
    cout << "Студент: " << (user.isStudent ? "Так" : "Ні") << endl;
}

int main()
{
    setlocale(LC_ALL, "ukr");

    vector<User> users;
    char moreUsers = 'y';

    while (moreUsers == 'y' || moreUsers == 'Y')
    {
        User user = inputUser();
        users.push_back(user);

        cout << "Бажаєте додати ще одного користувача? (y/n): ";
        cin >> moreUsers;
    }

    cout << "\nДані про всіх користувачів";

    for (size_t i = 0; i < users.size(); ++i)
    {
        cout << "\nКористувач" << i + 1 << ":\n";
        displayUser(users[i]);
    }
    return 0;

}
