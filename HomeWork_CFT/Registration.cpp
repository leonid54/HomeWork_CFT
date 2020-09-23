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
		cout << "��� ������ ��������� ����� 1 �����!" << endl;
		cout<< "������� ���:";
		cin >> name;
		Data::CheckName();
	}
}

void Data::CheckSurname()
{
	if (surname.size() < 3)
	{
		cout << "������� ������ ��������� ����� ���� ����!" << endl;
		cout << "������� �������:";
		cin >> surname;
		Data::CheckSurname();
	}
}

void Data::CheckDataBitrh()
{
	if (DataBirth.size() < 10)
	{
		cout << "���� �������� ������ ��������� �� ����� 10 ������!" << endl;
		cout << "������� ���� ��������:";
		cin >> DataBirth;
		Data::CheckDataBitrh();
	}
}

void Data::CheckPassword()
{
	if (password.size() < 5)
	{
		cout << "������ ������ ��������� �� ����� 5 ������"<<endl;
		cout << "���������� ������:";
		cin >> password;
		Data::CheckPassword();
	}
}

void Data::CheckRepeatPassword()
{
	if (password != RepeatPassword)
	{
		cout << "������ �� ���������!" << endl;
		cout << "����������� ������:";
		cin >> RepeatPassword;
		Data::CheckRepeatPassword();
	}
}

void Data::CheckVolidatiton()
{
	cout << "�����������(yes/no)?" << endl;
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
		cout << "������ �����������! " << endl;
	}
	else
	{
		cout << "��� ����������� ����������� ������� 'yes', ��� ������ 'no' " << endl;
		Data::CheckVolidatiton();
	
	}
}