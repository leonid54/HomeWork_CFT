#pragma once
#include <iostream>
#include <string>
using namespace std;

class Data
{
public:
	
	Data(string name, string surname, string DataBirth, string password,string RepeatPassword);
	void CheckName();
	void CheckSurname();
	void CheckDataBitrh();
	void CheckPassword();
	void CheckRepeatPassword();
	void CheckVolidatiton();

private:
	string name, surname, DataBirth, password, RepeatPassword;
	string answer;
};
