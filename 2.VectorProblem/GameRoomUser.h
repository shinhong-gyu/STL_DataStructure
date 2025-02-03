#pragma once

#include <vector>
#include <string>

#define MAX_USER_COUNT 6

using namespace std;

// ���� ����
struct UserInfo
{
	UserInfo() : userName(""), level(0), exp(0) {}
	UserInfo(const char* _userName, int _level, int _exp)
	{
		userName = _userName;
		level = _level;
		exp = _exp;
	}


	bool operator==(const UserInfo& userInfo)
	{
		return userName == userInfo.userName && level == userInfo.level && exp == userInfo.exp;
	}

	string userName; // �̸�
	int level; // ����
	int exp; // ����ġ
};

// ���� ���� ������ �����ϴ� Ŭ����
// �濡�� �ִ� 6����� ��� �� �� �ִ�.
// �濡 ��� ���� ���� �� ���� ���� ��� �� ����� ������ �ȴ�.
class GameRoomUser
{
public:
	GameRoomUser();
	~GameRoomUser();

	// �濡 ���� �߰�
	bool AddUser(UserInfo& userInfo);

	// �濡�� ���� ����.
	// ���� ������ ������ userName�� ���ο� ������ �̸��� ���� �ؾ� �ȴ�.
	bool DeleteUser(const char* userName);

	// �濡 ������ ������ Ȯ��. ������ true ��ȯ
	bool IsEmpty();

	// �濡 ������ �� á���� Ȯ��. �� á�ٸ� true ��ȯ
	bool IsFull();

	// Ư�� ������ ����
	bool GetUserOfName(const char* userName,UserInfo& outValue);

	// ������ ���� ����
	bool GetMasterUser(UserInfo& outValue);

	// ���� �������� �濡 ��� �� ������ ����
	bool GetUserOfLastOrder(UserInfo& outValue);

	// Ư�� ������ ��� �� ������ �i�Ƴ���.
	bool BanUser(int orderNum);

	// ��� ������ �����Ѵ�.
	void Clear();

private:
	std::vector<UserInfo> users;
	string masterUserName; // ������ �̸�
};