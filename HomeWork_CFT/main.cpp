//ЗАДАНИЕ ДЛЯ ЦФТ
#include <iostream>
#include "Registration.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
	string name, surname, DataBirth, password, RepeatPassword;
	cout << "Регистрация нового пользователя:" <<endl
		 <<"Введите Имя:";
	cin >> name;
	cout << "Введите Фамилию:";
	cin >> surname;
	cout << "Введите Дату Рождения:";
	cin >> DataBirth;
	cout << "Придумайте Пароль:";
	cin >> password;
	cout << "Подтвердите Пароль:";
	cin >> RepeatPassword;
	Data a(name, surname, DataBirth, password,RepeatPassword);
	a.CheckVolidatiton();
	return 0;
}