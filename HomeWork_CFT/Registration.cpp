#include "Registration.h"
#pragma once

Entry::Entry()
{

}
bool Entry::CheckSize(string name)
{
	return(name.size() >= 2);
}

bool Entry::isStringAlpha(const string& name)
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
bool Entry::CheckDataBirth(string DataBirth)
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

bool Entry::isStringNumber(const string& name)
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

bool Entry::CheckPassword(string password)
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

bool Entry::CheckrepeatPassword(string password,string repeatPassword)
{
	return(password == repeatPassword);
}
bool Entry::CheckValidatiton(string & answer,string & msg)
{
	if (answer != "yes" && answer != "no")
	{
		msg="Необходимо ввести 'yes' для продолжения, 'no' для выхода!";
		return false;
	}
	return true;
}

void Entry::SetName(string name) 
{
	m_name = name;
}
void Entry::SetSurname(string surname)
{
	m_surname = surname;
}
void Entry::SetDataBirth(string DataBirth)
{
	m_DataBirth = DataBirth;
}
void Entry::SetPassword(string password)
{
	m_password = password;
}
string Entry::getName()
{
	return m_name;
}
string Entry::getSurname()
{
	return m_surname;
}

bool Entry::CheckEnterPassword(string password)
{
	return(password == m_password);
}