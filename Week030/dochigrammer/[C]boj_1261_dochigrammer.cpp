#include <iostream>
#include <queue>

struct Point
{
	int x;
	int y;

	Point(int _x, int _y)
		:x(_x)
		, y(_y)
	{
	}

	Point()
		:x(0)
		, y(0)
	{

	}
	Point operator+(const Point& other)
	{
		return Point(x + other.x, y + other.y);
	}
};

int main()
{
	const static unsigned int MAX_INT = 2147483647;

	int row = 0, col = 0;

	std::cin >> row >> col;

	char* map = new char[row * col];

	for (int y = 0; y < col; ++y)
	{
		for (int x = 0; x < row; ++x)
		{
			std::cin >> map[x + row * y];
		}
	}

	int* costs = new int[row * col];

	for (int i = 0; i < row * col; ++i)
		costs[i] = MAX_INT;

	std::queue<Point> queue;

	queue.push(Point(0, 0));
	costs[0] = 0;

	while (queue.empty() == false)
	{
		Point pt = queue.front();
		queue.pop();

		auto func_push_pt = [&](int curr_cost, Point _moved_pt)
		{
			if (_moved_pt.x < 0 || _moved_pt.y < 0 || _moved_pt.x >= row || _moved_pt.y >= col)
			{
				return;
			}

			if (map[_moved_pt.x + row * _moved_pt.y] == '1')
			{
				curr_cost++;
			}

			if (curr_cost < costs[_moved_pt.x + row * _moved_pt.y])
			{
				costs[_moved_pt.x + row * _moved_pt.y] = curr_cost;
				queue.push(_moved_pt);
			}
		};

		int curr_cost = costs[pt.x + row * pt.y];

		func_push_pt(curr_cost, pt + Point(1, 0));
		func_push_pt(curr_cost, pt + Point(0, 1));
		func_push_pt(curr_cost, pt + Point(-1, 0));
		func_push_pt(curr_cost, pt + Point(0, -1));
	}

	std::cout << costs[row * col - 1];

	delete[] map;
	delete[] costs;
}
