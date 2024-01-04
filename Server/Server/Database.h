#pragma once
#include <string>
#include <sqlite_orm/sqlite_orm.h>

#include "User.h"
#include "Room.h"
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
				sql::make_column("id", &User::SetId, &User::GetId, sql::primary_key(), sql::autoincrement()),
				sql::make_column("name", &User::SetName, &User::GetName),
				sql::make_column("email", &User::SetEmail, &User::GetEmail),
				sql::make_column("password", &User::SetPassword, &User::GetPassword),
				sql::make_column("image_path", &User::SetImagePath, &User::GetImagePath),
				sql::make_column("role", &User::SetRole, &User::GetRole)
			),
			sql::make_table(
				"Room",
				sql::make_column("id", &Room::SetId, &Room::GetId, sql::primary_key(), sql::autoincrement()),
				sql::make_column("host_id", &Room::SetHostId, &Room::GetHostId),
				sql::make_column("max_players", &Room::SetMaxPlayers, &Room::GetMaxPlayers),
				sql::make_column("draw_time", &Room::SetDrawTime, &Room::GetDrawTime),
				sql::make_column("room_code", &Room::SetRoomCode, &Room::GetRoomCode)
			),
			sql::make_table(
				"RoomsPlayers",
				sql::make_column("id", &RoomPlayer::SetId, &RoomPlayer::GetId, sql::primary_key(), sql::autoincrement()),
				sql::make_column("room_id", &RoomPlayer::SetRoomId, &RoomPlayer::GetRoomId),
				sql::make_column("user_name", &RoomPlayer::SetUser, &RoomPlayer::GetUser)
			)
		);
	};

	using Storage = decltype(CreateStorage(""));
}