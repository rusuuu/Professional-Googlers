#include "UserHelper.h"

std::vector<std::string> ExtractNames(const std::vector<User>& users)
{
	std::vector<std::string> names;
	for (const auto& user : users)
	{
		names.push_back(user.GetName());
	}

	return names;
}

std::vector<std::string> ExtractEmails(const std::vector<User>& users)
{
	std::vector<std::string> emails;
	for (const auto& user : users)
	{
		emails.push_back(user.GetEmail());
	}

	return emails;
}
