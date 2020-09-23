//������� ��� ���
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
	cout << "����������� ������ ������������:" <<endl
		 <<"������� ���(���������:��� �� ������ ��������� ���������,�����):";
	cin >> name;

	cout << "������� �������(���������:������� �� ������ ��������� ���������,�����):";
	cin >> surname;
	
	cout << "������� ���� ��������(������: 08.03.2001):";
	cin >> DataBirth;
	
	cout << "���������� ������(�� 5 �� 16 ������):";
	cin >> password;
	
	cout << "����������� ������:";
	cin >> repeatPassword;
	
	cout << "�����������(yes/no)?" << endl;
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
		while (!a.CheckPassword(password))
		{
			cout << "������ �� ����� ����� ������ 5 � ������ 15 ������" << endl;
			cout << "���������� ������:";
			cin >> password;
		}
		while (!a.CheckrepeatPassword(password, repeatPassword))
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
			cin >> repeatPassword;
		}
		a.SetPassword(password);
	    system("cls");
	    cout << "�����������" << endl;
	}
	else
	{
		cout << "������ �����������!" << endl;
	}
	Entry entry;
	entry.saveToFile();
	if (answer == "yes")
	{
		cout << "�����?(yes/no)" << endl;
		cin >> answer;
		if (answer == "yes")
		{
			cout << "������� ������: ";
			cin >> password;
			while (!a.CheckEnterPassword(password))
			{
				cout << "�������� ������!" << endl << "������� ������: ";
				cin >> password;
			}
			cout << "����� ����������, " << a.getName() << " " << a.getSurname() << endl;
		}
		else if (answer == "no")
		{
			cout << "������ �����" << endl;
		}
		else
		{
			cout << "������!���������� ������ 'yes' ��� �����������, 'no' ��� ������!" << endl;
		}
	}
	return 0;
}