#include "pch.h"
#include "User.h"

User::User()
{
	m_id = -1;
	m_name = std::string();
	m_email = std::string();
	m_password = std::string();
	m_imagePath = std::string();
}

User::User(const int id, const std::string& name, const std::string& email, const std::string& password)
{
	m_id = id;
	m_name = name;
	m_email = email;
	m_password = password;
	m_imagePath = std::string();
}

void User::SetId(int id)
{
	m_id = id;
}

void User::SetName(const std::string& name)
{
	m_name = name;
}

void User::SetEmail(const std::string& email)
{
	m_email = email;
}

void User::SetPassword(const std::string& password)
{
	m_password = password;
}

void User::SetImagePath(const std::string& imagePath)
{
	m_imagePath = imagePath;
}

int User::GetId() const
{
	return m_id;
}

std::string User::GetName() const
{
	return m_name;
}

std::string User::GetEmail() const
{
	return m_email;
}

std::string User::GetPassword() const
{
	return m_password;
}

std::string User::GetImagePath() const
{
	return m_imagePath;
}