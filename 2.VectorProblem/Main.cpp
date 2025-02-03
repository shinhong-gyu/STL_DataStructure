#include "GameRoomUser.h"
#include <iostream>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

ostream& operator<<(ostream& os, UserInfo& userInfo)
{
	return os << "UserName: " << userInfo.userName
		<< ", Level: " << userInfo.level << ", Exp: " << userInfo.exp << endl;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// �� ����.
	GameRoomUser gameRoom;

	// ���� �߰�.
	UserInfo user1("RonnieJ", 1, 30);
	gameRoom.AddUser(user1);

	UserInfo user2("Hamtol2", 10, 670);
	gameRoom.AddUser(user2);

	UserInfo user3("TaeJun", 5, 250);
	gameRoom.AddUser(user3);

	UserInfo user4("Oops", 32, 1250);
	gameRoom.AddUser(user4);

	UserInfo user5("Gamer", 40, 250);
	gameRoom.AddUser(user5);

	UserInfo user6("GameDev", 80, 3425);
	gameRoom.AddUser(user6);

	UserInfo user7("STL", 23, 890);
	gameRoom.AddUser(user7);

	// ���� Ȯ��.
	UserInfo roomMaster;

	if (gameRoom.GetMasterUser(roomMaster) == true)
	{
		cout << "������ " << roomMaster.userName << " �Դϴ�.\n";
	}
	else
	{
		cout << "������ �����ϴ�.\n";
	}

	// ���� ��.
	gameRoom.BanUser(1);

	// 3�� ��.
	gameRoom.BanUser(3);

	UserInfo outResult;
	// GameDev�� ���� Ȯ��.
	if (gameRoom.GetUserOfName("TaeJun", outResult))
	{
		cout << "[TaeJun�� ����] " << outResult;
	}
	else
	{
		cout << "TaeJun�� ������ ã�� �� �����ϴ�.\n";
	}
	// �������� �濡 ���� ���� ����.
	if (gameRoom.GetUserOfLastOrder(outResult))
	{
		cout << "[������ ���� ����] " << outResult;
	}
	else
	{
		cout << "������ ���� ������ ã�� �� �����ϴ�.\n";
	}
	// ��� ���� ����.
	gameRoom.Clear();

	// ��� ���� ���� �� ������� Ȯ��.
	cout << (gameRoom.IsEmpty() == true ? "���� ������ϴ�.\n" : "���� ������� �ʽ��ϴ�\n");

	cin.get();
}