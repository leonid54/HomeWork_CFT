//ЗАДАНИЕ ДЛЯ ЦФТ
#include <iostream>

#include "Registration.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
	Entry a;
	string name, surname, DataBirth, password, repeatPassword,answer,msg;
	Entry loadedEntry;
	if (loadedEntry.loadFromFile())
	{
		std::cout << loadedEntry.getName() << " " << loadedEntry.getSurname() << " " << loadedEntry.getPassword() << endl;

	}
	cout << "Регистрация нового пользователя:" <<endl
		 <<"Введите Имя(Подсказка:Имя не должно содержать кириллицу,цифры):";
	cin >> name;

	cout << "Введите Фамилию(Подсказка:Фамилия не должна содержать кириллицу,цифры):";
	cin >> surname;
	
	cout << "Введите Дату Рождения(пример: 08.03.2001):";
	cin >> DataBirth;
	
	cout << "Придумайте Пароль(от 5 до 16 знаков):";
	cin >> password;
	
	cout << "Подтвердите Пароль:";
	cin >> repeatPassword;
	
	cout << "Регистрация(yes/no)?" << endl;
	cin >> answer;

	while(!a.CheckValidatiton(answer,msg))
	{
		cout << msg << endl;
		cin >> answer;
	}
	if (answer == "yes")
	{
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
		while (!a.CheckPassword(password))
		{
			cout << "Пароль не может иметь меньше 5 и больше 15 знаков" << endl;
			cout << "Придумайте Пароль:";
			cin >> password;
		}
		while (!a.CheckrepeatPassword(password, repeatPassword))
		{
			cout << "Пароли не совпадают!" << endl;
			cout << "Придумайте Пароль:";
			cin >> password;
			while (!a.CheckPassword(password))
			{
				cout << "Пароль не может иметь меньше 5 и больше 15 знаков" << endl;
				cout << "Придумайте Пароль:";
				cin >> password;
			}
			cout << "Подтвердите Пароль:";
			cin >> repeatPassword;
		}
		a.SetPassword(password);
	    system("cls");
	    cout << "Приветствие" << endl;
	}
	else
	{
		cout << "Отмена регистрации!" << endl;
	}
	Entry entry;
	entry.saveToFile();
	if (answer == "yes")
	{
		cout << "Войти?(yes/no)" << endl;
		cin >> answer;
		if (answer == "yes")
		{
			cout << "Введите пароль: ";
			cin >> password;
			while (!a.CheckEnterPassword(password))
			{
				cout << "Неверный пароль!" << endl << "Введите пароль: ";
				cin >> password;
			}
			cout << "Добро пожаловать, " << a.getName() << " " << a.getSurname() << endl;
		}
		else if (answer == "no")
		{
			cout << "Отмена входа" << endl;
		}
		else
		{
			cout << "Ошибка!Необходимо ввести 'yes' для продолжения, 'no' для выхода!" << endl;
		}
	}
	return 0;
}