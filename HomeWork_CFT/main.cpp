//ЗАДАНИЕ ДЛЯ ЦФТ
#include <iostream>
#include "Registration.h"
using namespace std;

void fillParams(string &name, string& surname, string& dataBirth, string& password, string& repeatPassword, string& answer)
{
	cout << "Регистрация нового пользователя:" << endl
		<< "Введите Имя(Подсказка:Имя не должно содержать кириллицу,цифры):";
	cin >> name;

	cout << "Введите Фамилию(Подсказка:Фамилия не должна содержать кириллицу,цифры):";
	cin >> surname;

	cout << "Введите Дату Рождения(пример: 08.03.2001):";
	cin >> dataBirth;

	cout << "Придумайте Пароль(от 5 до 16 знаков):";
	cin >> password;

	cout << "Подтвердите Пароль:";
	cin >> repeatPassword;

	cout << "Регистрация(yes/no)?" << endl;
	cin >> answer;
}

int main()
{
    setlocale(LC_ALL, "ru");
	Entry entry;
	string name, surname, dataBirth, password, repeatPassword,answer,msg;
	Entry loadedEntry;
	if (loadedEntry.loadFromFile())
	{
		cout << "Хотите войти как: " << loadedEntry.getName() << " " << loadedEntry.getSurname() << "?(yes/no)" << endl;
		cin >> answer;
	}
	if (answer == "no" || !loadedEntry.loadFromFile())
	{
		fillParams(name, surname, dataBirth, password, repeatPassword, answer);
		
		while (!entry.checkValidatiton(answer, msg))
		{
			cout << msg << endl;
			cin >> answer;
		}
		if (answer == "yes")
		{
			while (!entry.checkSize(name))
			{
				cout << "Имя должно содержать более 1 буквы!(Подсказка:Имя не должно содержать кириллицу)" << endl;
				cout << "Введите Имя:";
				cin >> name;
			}
			while (!entry.isStringAlpha(name))
			{
				cout << "Имя должно содержать только буквы!" << endl;
				cout << "Введите Имя:";
				cin >> name;
			}
			entry.setName(name);
			while (!entry.checkSize(surname))
			{
				cout << "Фамилия должна содержать более 1 буквы!(Подсказка:Фамилия не должна содержать кириллицу)" << endl;
				cout << "Введите Фамилию:";
				cin >> surname;
			}
			while (!entry.isStringAlpha(surname))
			{
				cout << "Фамилия должна содержать только буквы!" << endl;
				cout << "Введите Фамилию:";
				cin >> surname;
			}
			entry.setSurname(surname);
			while (!entry.checkDataBirth(dataBirth))
			{
				cout << "Дата рождения должна содержать 10 чисел(пример: 08.03.2001)" << endl;
				cout << "Введите Дату Рождения:";
				cin >> dataBirth;
			}
			while (!entry.isStringNumber(dataBirth))
			{
				cout << "Дата рождения должна содержать только цифры(пример: 08.03.2001)" << endl;
				cout << "Введите Дату Рождения:";
				cin >> dataBirth;
			}
			entry.setdataBirth(dataBirth);
			while (!entry.checkPassword(password))
			{
				cout << "Пароль не может иметь меньше 5 и больше 15 знаков" << endl;
				cout << "Придумайте Пароль:";
				cin >> password;
			}
			while (!entry.checkrepeatPassword(password, repeatPassword))
			{
				cout << "Пароли не совпадают!" << endl;
				cout << "Придумайте Пароль:";
				cin >> password;
				while (!entry.checkPassword(password))
				{
					cout << "Пароль не может иметь меньше 5 и больше 15 знаков" << endl;
					cout << "Придумайте Пароль:";
					cin >> password;
				}
				cout << "Подтвердите Пароль:";
				cin >> repeatPassword;
			}
			entry.setPassword(password);
			system("cls");
			cout << "Приветствие" << endl;
		}
		else
		{
			cout << "Отмена регистрации!" << endl;
		}

		entry.saveToFile();
		if (answer == "yes")
		{
			cout << "Войти?(yes/no)" << endl;
			cin >> answer;
			if (answer == "yes")
			{
				cout << "Введите пароль: ";
				cin >> password;
				while (!entry.checkEnterPassword(password))
				{
					cout << "Неверный пароль!" << endl << "Введите пароль: ";
					cin >> password;
				}
				cout << "Добро пожаловать, " << entry.getName() << " " << entry.getSurname() << endl;
			}
			else if (answer == "no")
			{
				cout << "Отмена входа" << endl;
				return 0;
			}
			else
			{
				cout << "Ошибка!Необходимо ввести 'yes' для продолжения, 'no' для выхода!" << endl;
			}

		}
	}
		
		else if (answer == "yes")
		{
			cout << "Введите пароль: ";
			cin >> password;
			while (password != loadedEntry.getPassword())
			{
				cout << "Неверный пароль!" << endl << "Введите пароль: ";
				cin >> password;
			}
			cout << "Добро пожаловать, " << loadedEntry.getName() << " " << loadedEntry.getSurname() << endl;
		}
		else
		{
			cout << "Ошибка!Необходимо ввести 'yes' для продолжения, 'no' для выхода!" << endl;
		}
	
	return 0;
}