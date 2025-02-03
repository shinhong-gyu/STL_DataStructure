#include <iostream>
#include <list>
#include <algorithm>


#define endl '\n'; 
struct Item
{
	Item(int code = 0, int price = 0) : code(code), price(price) {};


	int code = 0; // ������ �ڵ�
	int price = 0; // ������ ����
};

// ������ ��¿� ������ �����ε�.
std::ostream& operator<<(std::ostream& os, const Item& item)
{
	return os << "Code: " << item.code << ", Price: " << item.price << endl;
}

// ������ �ڵ带 �������� �����ϴ� �Լ� ��ü (Functor).
struct ItemLessComparer
{
	bool operator()(const Item& left, const Item& right) const
	{
		return left.code < right.code;
	}
};

int main()
{
	// ����Ʈ ����.
	std::list<Item> itemList;

	// ������ �߰�.
	itemList.emplace_front(Item(1, 1000));
	itemList.emplace_front(Item(2, 2000));

	itemList.emplace_back(Item(3, 3000));
	itemList.emplace_back(Item(4, 4000));

	// ����Ʈ ���.
	for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
	{
		std::cout << *iter << endl;
	}

	// 	for (auto& item : itemList)
	// 	{
	// 		std::cout << item << endl;
	// 	}

		// ù ��° ������ ����.
	itemList.pop_front();

	Item& frontItem = itemList.front();

	std::cout << frontItem << endl;

	itemList.emplace_back(Item(8, 6333));
	itemList.emplace_back(Item(6, 4333));
	itemList.emplace_back(Item(5, 3333));
	itemList.emplace_back(Item(7, 5333));

	for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
	{
		std::cout << *iter << endl;
	}

	ItemLessComparer lessComparer;
	itemList.sort(lessComparer);

	for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
	{
		std::cout << *iter << endl;
	}

	itemList.sort
	(
		[](const Item& left, const Item& right) /*-> bool*/
		{
			return left.price > right.price;
		}
	);

	for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
	{
		std::cout << *iter << endl;
	}

	// 	std::sort(itemList.begin(), itemList.end(), lessComparer);
	// 	for (std::list<Item>::iterator iter = itemList.begin(); iter != itemList.end(); ++iter)
	// 	{
	// 		std::cout << *iter << endl;
	// 	}

	std::cin.get();
}