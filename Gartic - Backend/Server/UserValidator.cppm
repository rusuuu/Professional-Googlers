export module UserValidator;

import <string>;
import <vector>;
import <iostream>;
import <stdexcept>;

export void CheckNames(const std::string& name, const std::vector<std::string>& names);
export void CheckEmails(const std::string& email, const std::vector < std::string>& emails);