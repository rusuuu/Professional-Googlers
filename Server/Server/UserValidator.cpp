module UserValidator;

void CheckNames(const std::string& name, const std::vector<std::string>& names)
{
	for (const auto& existingName : names)
	{
		if (existingName == name)
		{
			throw std::invalid_argument("Name already exists");
		}
	}
}

void CheckEmails(const std::string& email, const std::vector<std::string>& emails)
{
	for (const auto& existingEmail : emails)
	{
		if (existingEmail == email)
		{
			throw std::invalid_argument("Email already exists");
		}
	}
}