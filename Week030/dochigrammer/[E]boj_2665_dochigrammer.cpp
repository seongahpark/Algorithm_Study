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
	int maze_size = 0;
	std::cin >> maze_size;

	char* map = new char[maze_size * maze_size];
	for (int y = 0; y < maze_size; ++y)
	{
		for (int x = 0; x < maze_size; ++x)
		{
			std::cin >> map[x + y * maze_size];
		}
	}

	int* costs = new int[maze_size * maze_size];
	for (int i = 0; i < maze_size * maze_size; ++i)
		costs[i] = MAX_INT;

	std::queue<Point> queue;

	queue.push(Point(0, 0));
	costs[0] = 0;
	if (map[0] == '0')
	{
		costs[0] = 1;
	}

	while (queue.empty() == false)
	{
		Point pt = queue.front();
		queue.pop();

		auto func_push_pt = [&](int curr_cost, Point _moved_pt)
		{
			if (_moved_pt.x < 0 || _moved_pt.y < 0 || _moved_pt.x >= maze_size || _moved_pt.y >= maze_size)
			{
				return;
			}

			if (map[_moved_pt.x + maze_size * _moved_pt.y] == '0')
			{
				++curr_cost;
			}

			if (curr_cost < costs[_moved_pt.x + maze_size * _moved_pt.y])
			{
				costs[_moved_pt.x + maze_size * _moved_pt.y] = curr_cost;
				queue.push(_moved_pt);
			}
		};

		int cost = costs[pt.x + maze_size * pt.y];

		func_push_pt(cost, pt + Point(1, 0));
		func_push_pt(cost, pt + Point(0, 1));
		func_push_pt(cost, pt + Point(-1, 0));
		func_push_pt(cost, pt + Point(0, -1));
	}

	std::cout << costs[maze_size * maze_size - 1] << "\n";

	delete[] map;
	delete[] costs;
}