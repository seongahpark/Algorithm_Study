#include <iostream>
#include <vector>
#include <queue>
#include <functional>

class IOHelper
{
public:
	template <typename T>
	static void Read(int loop_count, T* arg)
	{
		for (int i = 0; i < loop_count; ++i)
		{
			std::cin >> (*arg++);
		}
	}

	template <typename T, typename ... Types>
	static void Read(int loop_count, T* arg, Types* ... args)
	{
		if (arg != nullptr)
		{
			Read(loop_count, arg);
			Read(loop_count, args...);
		}
	}

	template <typename Proc>
	static void Read(int loop_count, Proc add_proc)
	{
		int value;
		for (int i = 0; i < loop_count; ++i)
		{
			std::cin >> value;
			add_proc(value);
		}
	}

	template <typename T>
	static void Print(int loop_count, T arg)
	{
		std::cout << (arg);
	}

	template <typename T, typename ... Types>
	static void Print(int loop_count, T arg, Types ... args)
	{
		Print(loop_count, arg);
		Print(loop_count, args...);
	}
};

struct Point
{
	int x;
	int y;


	Point()
		:x(0)
		, y(0)
	{

	}
	Point(int _x, int _y)
		:x(_x)
		, y(_y)
	{

	}


	Point& operator+=(const Point& _other)
	{
		this->x += _other.x;
		this->y += _other.y;
		return *this;
	}

	Point operator+(const Point& _other)
	{
		Point pt;
		pt.x = this->x + _other.x;
		pt.y = this->y + _other.y;

		return pt;
	}
};

int main()
{
	Point start, world;
	int time;

	IOHelper::Read(2, &world.x, &start.x);
	IOHelper::Read(1, &time);

	start.x += time;
	start.y += time;
	

	// 짝수 홀수로 벽을 튕겨나서 어느방향을 보고있는지 확인
	bool is_negative_x, is_negative_y;
	is_negative_x = (start.x / world.x) % 2 == 1;
	is_negative_y = (start.y / world.y) % 2 == 1;

	// 정 방향이면 최대 좌표로 나눈값이 마지막 위치
	Point result;
	result.x = start.x % world.x;
	result.y = start.y % world.y;

	// 반대 방향이면 최대 좌표에서 나머지값을 뺀다
	if (is_negative_x)
	{
		result.x = world.x - result.x;
	}

	if (is_negative_y)
	{
		result.y = world.y - result.y;
	}

	IOHelper::Print(1, result.x, " ", result.y);

	return 0;
}