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
	int cave_size = 0;
	std::cin >> cave_size;

	int test_idx = 1;

	while (cave_size > 0)
	{
		int* map = new int[cave_size * cave_size];
		for (int y = 0; y < cave_size; ++y)
		{
			for (int x = 0; x < cave_size; ++x)
			{
				std::cin >> map[x + y * cave_size];
			}
		}

		int* costs = new int[cave_size * cave_size];
		for (int i = 0; i < cave_size * cave_size; ++i)
			costs[i] = MAX_INT;

		std::queue<Point> queue;

		queue.push(Point(0, 0));
		costs[0] = map[0];

		while (queue.empty() == false)
		{
			Point pt = queue.front();
			queue.pop();

			auto func_push_pt = [&](int curr_cost, Point _moved_pt)
			{
				if (_moved_pt.x < 0 || _moved_pt.y < 0 || _moved_pt.x >= cave_size || _moved_pt.y >= cave_size)
				{
					return;
				}

				curr_cost += map[_moved_pt.x + cave_size * _moved_pt.y];

				if (curr_cost < costs[_moved_pt.x + cave_size * _moved_pt.y])
				{
					costs[_moved_pt.x + cave_size * _moved_pt.y] = curr_cost;
					queue.push(_moved_pt);
				}
			};

			int cost = costs[pt.x + cave_size * pt.y];

			func_push_pt(cost, pt + Point(1, 0));
			func_push_pt(cost, pt + Point(0, 1));
			func_push_pt(cost, pt + Point(-1, 0));
			func_push_pt(cost, pt + Point(0, -1));
		}

		std::cout << "Problem " << test_idx << ": " << costs[cave_size * cave_size - 1] << "\n";

		++test_idx;

		delete[] map;
		delete[] costs;

		std::cin >> cave_size;
	}
}