//������� ��� ���
#include <iostream>
#include "Registration.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
	string name, surname, DataBirth, password, RepeatPassword;
	cout << "����������� ������ ������������:" <<endl
		 <<"������� ���:";
	cin >> name;
	cout << "������� �������:";
	cin >> surname;
	cout << "������� ���� ��������:";
	cin >> DataBirth;
	cout << "���������� ������:";
	cin >> password;
	cout << "����������� ������:";
	cin >> RepeatPassword;
	Data a(name, surname, DataBirth, password,RepeatPassword);
	a.CheckVolidatiton();
	return 0;
}