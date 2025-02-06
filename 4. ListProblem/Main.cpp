#include <list>
#include <iostream>
#include <string>

using namespace std;

struct Point
{
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

struct Node
{
	Point p;
	string name;
};

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	return os << node.name << " (" << node.p.x << ", " << node.p.y << ")";
}

int main()
{
	list<Node> shape;
	shape.emplace_back(Node{ Point(50, 200), "A" });
	shape.emplace_back(Node{ Point(20, 80), "B" });
	shape.emplace_back(Node{ Point(75, 10), "C" });
	shape.emplace_back(Node{ Point(130,80), "D" });
	shape.emplace_back(Node{ Point(100, 200), "E" });

	for (auto iter = shape.begin(); iter != shape.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	cout << "\n";
	auto iter = shape.begin();
	iter++;
	iter++;
	iter++;
	iter++;
	shape.insert(iter, Node{ Point(180,150), "F" });

	for (auto iter = shape.begin(); iter != shape.end(); ++iter)
	{
		std::cout << *iter << " ";
	}

	cout << "\n";
	for (auto iter = shape.begin(); iter != shape.end(); ++iter)
	{
		if (iter->name == "D")
		{
			iter->p = Point(200, 100);
			break;
		}
	}


	for (auto iter = shape.begin(); iter != shape.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	cout << "\n";
	for (auto iter = shape.begin(); iter != shape.end(); ++iter)
	{
		if (iter->name == "C")
		{
			shape.erase(iter);
			break;
		}
	}
	for (auto iter = shape.begin(); iter != shape.end(); ++iter)
	{
		std::cout << *iter << " ";
	}

}