#include <map>
#include <iostream>
#include <string>
#include <Windows.h>
#include <corecrt_io.h>
#include <fcntl.h>
#include <set>

// 구조체.
struct Item
{
	std::wstring name;
	unsigned int kind = 0;
	int price = 0;
	int code = 0;
};

// 출력을 위한 연산자 오버로딩.
std::wostream& operator<<(std::wostream& os, const Item& item)
{
	return os << "이름 : " << item.name << ", 가격" << item.price << ", 코드 : " << item.code;
}

int main()
{
	//int a = _setmode(_fileno(stdout), _O_U16TEXT);
	//setlocale(LC_ALL, ".949");
	// 맵 생성.
	std::map<std::wstring, Item, std::greater<std::wstring>> items;

	// 데이터 추가
	items.insert({ TEXT("장검") , { TEXT("장검"),1,200,0 } });
	items.insert({ TEXT("해머") , { TEXT("해머"),1,1000,4 } });
	items.insert({ TEXT("방패") , { TEXT("방패"),2,500,3 } });

	if (!items.empty())
	{
		std::wcout << "저장된 아이템 수 : " << items.size() << "\n";
	}


	for (auto& pair : items)
	{
		std::wcout << pair.second << L"\n";
		std::wcout.flush();
	}

	std::cin.get();
}