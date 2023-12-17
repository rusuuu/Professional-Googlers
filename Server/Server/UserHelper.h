#pragma once

#include <string>
#include <vector>

#include "User.h"

std::vector<std::string> ExtractNames(const std::vector<User>& users);
std::vector<std::string> ExtractEmails(const std::vector<User>& users);