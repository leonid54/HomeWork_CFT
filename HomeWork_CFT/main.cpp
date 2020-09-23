//ЗАДАНИЕ ДЛЯ ЦФТ
#include <iostream>
#include "Registration.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
	Data a;
	string name, surname, DataBirth, password, RepeatPassword;
	cout << "Регистрация нового пользователя:" <<endl
		 <<"Введите Имя(Подсказка:Имя не должно содержать кириллицу):";
	cin >> name;

	while (!a.CheckSize(name))
	{
		cout << "Имя должно содержать более 1 буквы!(Подсказка:Имя не должно содержать кириллицу)" << endl;
		cout << "Введите Имя:";
		cin >> name;
	}
	while (!a.isStringAlpha(name))
	{
		cout << "Имя должно содержать только буквы!" << endl;
		cout << "Введите Имя:";
		cin >> name;
	}
	a.SetName(name);
	cout << "Введите Фамилию(Подсказка:Фамилия не должна содержать кириллицу):";
	cin >> surname;
	while (!a.CheckSize(surname))
	{
		cout << "Фамилия должна содержать более 1 буквы!(Подсказка:Фамилия не должна содержать кириллицу)" << endl;
		cout << "Введите Фамилию:";
		cin >> surname;
	}
	while (!a.isStringAlpha(surname))
	{
		cout << "Фамилия должна содержать только буквы!" << endl;
		cout << "Введите Фамилию:";
		cin >> surname;
	}
	a.SetSurname(surname);
	cout << "Введите Дату Рождения(пример: 08.03.2001):";
	cin >> DataBirth;
	while (!a.CheckDataBirth(DataBirth))
	{
		cout << "Дата рождения должна содержать 10 чисел(пример: 08.03.2001)" << endl;
		cout << "Введите Дату Рождения:";
		cin >> DataBirth;
	}
	while (!a.isStringNumber(DataBirth))
	{
		cout << "Дата рождения должна содержать только цифры(пример: 08.03.2001)" << endl;
		cout << "Введите Дату Рождения:";
		cin >> DataBirth;
	}
	a.SetDataBirth(DataBirth);
	cout << "Придумайте Пароль(от 5 до 16 знаков):";
	cin >> password;
	while (!a.CheckPassword(password))
	{
		cout << "Пароль не может иметь меньше 5 и больше 15 знаков" << endl;
		cout << "Придумайте Пароль:";
		cin >> password;
	}
	a.SetPassword(password);
	cout << "Подтвердите Пароль:";
	cin >> RepeatPassword;
	while (!a.CheckRepeatPassword(password, RepeatPassword))
	{
		cout << "Пароли не совпадают!" << endl;
		cout << "Подтвердите Пароль:";
		cin >> RepeatPassword;
	}
	a.SetRepeatPassword(RepeatPassword);
	if (a.CheckVolidatiton() == true)
	{
		system("cls");
		cout << "Приветствие" << endl;
	}

	return 0;
}