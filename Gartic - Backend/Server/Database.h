#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>

#include "User.h"
#include "Room.h"
#include "UserStats.h"
#include "RoomPlayer.h"

namespace sql = sqlite_orm;

namespace Database
{
	inline auto CreateStorage(const std::string& fileName)
	{
		return sql::make_storage(
			fileName,
			sql::make_table(
				"User",
				sql::make_column("id", &User::SetId, &User::GetId, sql::primary_key().autoincrement()),
				sql::make_column("name", &User::SetName, &User::GetName),
				sql::make_column("email", &User::SetEmail, &User::GetEmail),
				sql::make_column("password", &User::SetPassword, &User::GetPassword),
				sql::make_column("image_path", &User::SetImagePath, &User::GetImagePath)
			),
			sql::make_table(
				"UserStats",
				sql::make_column("id", &UserStats::SetId, &UserStats::GetId, sql::primary_key().autoincrement()),
				sql::make_column("name", &UserStats::SetName, &UserStats::GetName),
				sql::make_column("total_games", &UserStats::SetTotalGames, &UserStats::GetTotalGames),
				sql::make_column("games_won", &UserStats::SetGamesWon, &UserStats::GetGamesWon),
				sql::make_column("games_lost", &UserStats::SetGamesLost, &UserStats::GetGamesLost),
				sql::make_column("total_points", &UserStats::SetTotalPoints, &UserStats::GetTotalPoints)
			)
		);
	};

	using Storage = decltype(CreateStorage(""));
}