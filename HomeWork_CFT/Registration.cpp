#include "Registration.h"
#pragma once

Data::Data()
{

}
bool Data::CheckSize(string name)
{
	if(name.size() < 2)
	{
		return false;
	}
	return true;
}

bool Data::isStringAlpha(const string& name)
{
	if (name.empty())
	{
		return false;
	}
	for (int i = 0; i < name.size(); i++)
	{
		if (!isalpha(name[i]))
		{
			return false;
		}
	}
	return true;
}
bool Data::CheckDataBirth(string DataBirth)
{
	if (DataBirth.size() < 10)
	{
		return false;
	}
	else if (DataBirth.size() > 10)
	{
		return false;
	}
	return true;
}

bool Data::isStringNumber(const string& name)
{
	if (name.empty())
	{
		return false;
	}
	for (int i = 0; i < name.size(); i++)
	{
		if (isalpha(name[i]) && name[i]!= '.')
		{
			return false;
		}
	}
	return true;
}

bool Data::CheckPassword(string password)
{
	if (password.size() < 5)
	{
		return false;
	}
	else if (password.size() > 15)
	{
		return false;
	}
	return true;
}

bool Data::CheckRepeatPassword(string password,string RepeatPassword)
{
	if (password != RepeatPassword)
	{
		return false;
	}
	return true;
}
bool Data::CheckVolidatiton(string & answer,string & msg)
{
	if (answer != "yes" && answer != "no")
	{
		msg="Необходимо ввести 'yes' для продолжения, 'no' для выхода!";
		return false;
	}
	return true;
}

void Data::SetName(string name) 
{
	m_name = name;
}
void Data::SetSurname(string surname)
{
	m_surname = surname;
}
void Data::SetDataBirth(string DataBirth)
{
	m_DataBirth = DataBirth;
}
void Data::SetPassword(string password)
{
	m_password = password;
}
