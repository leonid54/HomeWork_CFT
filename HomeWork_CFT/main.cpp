//������� ��� ���
#include <iostream>
#include "Registration.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
	Data a;
	string name, surname, DataBirth, password, RepeatPassword,answer,msg;
	cout << "����������� ������ ������������:" <<endl
		 <<"������� ���(���������:��� �� ������ ��������� ���������):";
	cin >> name;

	while (!a.CheckSize(name))
	{
		cout << "��� ������ ��������� ����� 1 �����!(���������:��� �� ������ ��������� ���������)" << endl;
		cout << "������� ���:";
		cin >> name;
	}
	while (!a.isStringAlpha(name))
	{
		cout << "��� ������ ��������� ������ �����!" << endl;
		cout << "������� ���:";
		cin >> name;
	}
	a.SetName(name);
	cout << "������� �������(���������:������� �� ������ ��������� ���������):";
	cin >> surname;
	while (!a.CheckSize(surname))
	{
		cout << "������� ������ ��������� ����� 1 �����!(���������:������� �� ������ ��������� ���������)" << endl;
		cout << "������� �������:";
		cin >> surname;
	}
	while (!a.isStringAlpha(surname))
	{
		cout << "������� ������ ��������� ������ �����!" << endl;
		cout << "������� �������:";
		cin >> surname;
	}
	a.SetSurname(surname);
	cout << "������� ���� ��������(������: 08.03.2001):";
	cin >> DataBirth;
	while (!a.CheckDataBirth(DataBirth))
	{
		cout << "���� �������� ������ ��������� 10 �����(������: 08.03.2001)" << endl;
		cout << "������� ���� ��������:";
		cin >> DataBirth;
	}
	while (!a.isStringNumber(DataBirth))
	{
		cout << "���� �������� ������ ��������� ������ �����(������: 08.03.2001)" << endl;
		cout << "������� ���� ��������:";
		cin >> DataBirth;
	}
	a.SetDataBirth(DataBirth);
	cout << "���������� ������(�� 5 �� 16 ������):";
	cin >> password;
	while (!a.CheckPassword(password))
	{
		cout << "������ �� ����� ����� ������ 5 � ������ 15 ������" << endl;
		cout << "���������� ������:";
		cin >> password;
	}

	cout << "����������� ������:";
	cin >> RepeatPassword;
	while (!a.CheckRepeatPassword(password, RepeatPassword))
	{
		cout << "������ �� ���������!" << endl;
		cout << "���������� ������:";
		cin >> password;
		while (!a.CheckPassword(password))
		{
			cout << "������ �� ����� ����� ������ 5 � ������ 15 ������" << endl;
			cout << "���������� ������:";
			cin >> password;
		}
		cout << "����������� ������:";
		cin >> RepeatPassword;
	}
	a.SetPassword(password);
	a.SetRepeatPassword(RepeatPassword);
	cout << "�����������(yes/no)?" << endl;
	cin >> answer;
	while(!a.CheckVolidatiton(answer,msg))
	{
		cout << msg << endl;
		cin >> answer;
	}
	if (answer == "yes")
	{
	    system("cls");
	    cout << "�����������" << endl;
	}
	else
	{
		cout << "������ �����������!" << endl;
	}

	return 0;
}