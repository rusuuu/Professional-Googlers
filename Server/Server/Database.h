#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>

#include "User.h"


namespace sql = sqlite_orm;

namespace Database
{
	inline auto CreateStorage(const std::string& fileName)
	{
		return sql::make_storage(
			fileName,
			sql::make_table(
				"User",
				sql::make_column("id", &User::SetId, &User::GetId, sql::primary_key(), sql::autoincrement()),
				sql::make_column("name", &User::SetName, &User::GetName),
				sql::make_column("email", &User::SetEmail, &User::GetEmail),
				sql::make_column("password", &User::SetPassword, &User::GetPassword),
				sql::make_column("image_path", &User::SetImagePath, &User::GetImagePath),
				sql::make_column("role", &User::SetRole, &User::GetRole)
			)
		);
	};

	using Storage = decltype(CreateStorage(""));
}