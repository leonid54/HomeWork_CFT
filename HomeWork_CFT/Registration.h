#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Entry
{
public:
	Entry();

	bool CheckSize(string name);
	bool isStringAlpha(const string& name);
	bool CheckDataBirth(string DataBirth);
	bool isStringNumber(const string& name);
	bool CheckPassword(string password);
	bool CheckrepeatPassword(string password,string repeatPassword);
	bool CheckValidatiton(string & answer, string& msg);
	void SetName(string name);
	void SetSurname(string surname);
	void SetDataBirth(string DataBirth);
	void SetPassword(string password);
	string getName();
	string getSurname();
	string getPassword();
	bool CheckEnterPassword(string password);
	void saveToFile();
	bool loadFromFile();

private:
	string m_name, m_surname, m_DataBirth, m_password, m_repeatPassword;
};
