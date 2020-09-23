#include "Registration.h"
#pragma once

Data::Data(string name, string surname, string DataBirth, string password, string RepeatPassword)
{
	this->name = name;
	this->surname = surname;
	this->DataBirth = DataBirth;
	this->password = password;
	this->RepeatPassword = RepeatPassword;
}
void Data::CheckName()
{
	if (name.size() < 2)
	{
		cout << "Имя должно содержать более 1 буквы!" << endl;
		cout<< "Введите Имя:";
		cin >> name;
		Data::CheckName();
	}
}

void Data::CheckSurname()
{
	if (surname.size() < 3)
	{
		cout << "Фамилия должна содержать более двух букв!" << endl;
		cout << "Введите Фамилию:";
		cin >> surname;
		Data::CheckSurname();
	}
}

void Data::CheckDataBitrh()
{
	if (DataBirth.size() < 10)
	{
		cout << "Дата Рождения должна содержать не менее 10 знаков!" << endl;
		cout << "Введите Дату Рождения:";
		cin >> DataBirth;
		Data::CheckDataBitrh();
	}
}

void Data::CheckPassword()
{
	if (password.size() < 5)
	{
		cout << "Пароль должен содержать не менее 5 знаков"<<endl;
		cout << "Придумайте Пароль:";
		cin >> password;
		Data::CheckPassword();
	}
}

void Data::CheckRepeatPassword()
{
	if (password != RepeatPassword)
	{
		cout << "Пароли не совпадают!" << endl;
		cout << "Подтвердите Пароль:";
		cin >> RepeatPassword;
		Data::CheckRepeatPassword();
	}
}

void Data::CheckVolidatiton()
{
	cout << "Регистрация(yes/no)?" << endl;
	cin >> answer;
	if (answer == "yes")
	{
		Data::CheckName();
		Data::CheckSurname();
		Data::CheckDataBitrh();
		Data::CheckPassword();
		Data::CheckRepeatPassword();

	}
	else if(answer == "no")
	{
		cout << "Отмена регистрации! " << endl;
	}
	else
	{
		cout << "Для продолжения регистрации введите 'yes', для отмены 'no' " << endl;
		Data::CheckVolidatiton();
	
	}
}