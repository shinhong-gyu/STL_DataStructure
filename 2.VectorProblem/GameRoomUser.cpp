#include "GameRoomUser.h"

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
	if (userInfo == UserInfo())
	{
		return false;
	}

	users.push_back(userInfo);
	return true;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (userName == users[i].userName)
		{
			delete& users[i];
			users.erase(users.begin() + i);
			return true;
		}
	}
	return false;
}

bool GameRoomUser::IsEmpty()
{
	if (users.size() == 0)
	{
		return true;
	}

	return false;
}

bool GameRoomUser::IsFull()
{
	if (users.size() == MAX_USER_COUNT)
	{
		return true;
	}
	return false;
}

bool GameRoomUser::GetUserOfName(const char* userName, UserInfo& outValue)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (userName == users[i].userName)
		{
			outValue = users[i];
			return true;
		}
	}
	return false;
}

bool GameRoomUser::GetMasterUser(UserInfo& outValue)
{
	for (auto user : users)
	{
		if (user.userName == masterUserName)
		{
			outValue = user;
			return true;
		}
	}
	return false;
}

bool GameRoomUser::GetUserOfLastOrder(UserInfo& outValue)
{
	UserInfo* userInfo = nullptr;

	if (users.size() == 0)
	{
		return false;
	}

	outValue = users[users.size() - 1];

	return true;
	
}

bool GameRoomUser::BanUser(int orderNum)
{
	if (orderNum - 1 < 0 || orderNum - 1 >= users.size())
	{
		return false;
	}

	users.erase(users.begin() + (orderNum - 1));

	return true;
}

void GameRoomUser::Clear()
{
	users.clear();
}
