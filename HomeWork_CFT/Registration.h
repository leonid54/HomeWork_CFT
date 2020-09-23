#pragma once
#include <iostream>
#include <string>
using namespace std;

class Data
{
public:
	Data();

	bool CheckSize(string name);
	bool isStringAlpha(const string& name);
	bool CheckDataBirth(string DataBirth);
	bool isStringNumber(const string& name);
	bool CheckPassword(string password);
	bool CheckRepeatPassword(string password,string RepeatPassword);
	bool CheckVolidatiton();
	void SetName(string name);
	void SetSurname(string surname);
	void SetDataBirth(string DataBirth);
	void SetPassword(string password);
	void SetRepeatPassword(string RepeatPassword);
private:
	string m_name, m_surname, m_DataBirth, m_password, m_RepeatPassword;
	string answer;
};
