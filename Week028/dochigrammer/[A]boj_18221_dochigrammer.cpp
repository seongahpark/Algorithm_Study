#include<bits/stdc++.h>

class IOHelper
{
protected:
	template <typename T>
	static void Read_Internal(int start_idx, int loop_count, T* arg)
	{
		for (int i = 0; i < loop_count; ++i)
		{
			std::cin >> (*(arg + start_idx + i));
		}
	}
public:
	template <typename T>
	static void Read(int start_idx, int loop_count, T* arg)
	{
		Read_Internal(start_idx, loop_count, arg);
	}

	template <typename T, typename ... Types>
	static void Read(int start_idx, int loop_count, T* arg, Types* ... args)
	{
		for (int i = 0; i < loop_count; ++i)
		{
			Read_Internal(i, 1, arg);
			Read(i, 1, args...);
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

	//template <typename T>
	//static void Print(int start_idx, int loop_count, T* arg)
	//{
	//	for (int i = 0; i < loop_count; ++i)
	//	{
	//		std::cout << (*(arg + start_idx + i));
	//	}
	//}

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
int Clamp(int val, int min, int max)
{
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

template <typename T>
int Min(T value, T other)
{
	if (value < other) return value;

	return other;
}


template <typename T, typename ... Types>
int Min(T value, T other, Types ... args)
{
	if (value < other)
	{
		return Min(value, args...);
	}

	return Min(other, args...);
}

template <typename T>
int Max(T value, T other)
{
	if (value < other) return other;

	return value;
}

template <typename T, typename ... Types>
int Max(T value, T other, Types ... args)
{
	if (value < other)
	{
		return Max(other, args...);
	}

	return Max(value, args...);
}

struct Point
{
	int x;
	int y;

	Point()
	{

	}

	Point(int _x, int _y)
		:x(_x)
		, y(_y)
	{

	}

	static float Length(const Point& lhs, const Point& rhs)
	{
		Point diff;
		diff.x = lhs.x - rhs.x;
		diff.y = lhs.y - rhs.y;

		return sqrt(diff.x * diff.x + diff.y * diff.y);
	}
};

int main()
{
	const int professor = 5;
	const int player = 2;
	const int other_student = 1;
	const int empty = 0;

	int count;
	IOHelper::Read(0, 1, &count);

	int* map = new int[count * count];

	Point professor_loc, player_loc;

	for (int y = 0; y < count; ++y)
	{
		for (int x = 0; x < count; ++x)
		{
			int input;
			IOHelper::Read(0, 1, &input);

			map[y * count + x] = input;

			// 위치 찾아서
			if (input == professor)
			{
				professor_loc = Point(x, y);
			}
			else if (input == player)
			{
				player_loc = Point(x, y);
			}
		}
	}

	// 거리가 5 미만이면 땡
	if (Point::Length(player_loc, professor_loc) < 5)
	{
		IOHelper::Print(1, 0);
		return 0;
	}

	int start_x = Min(player_loc.x, professor_loc.x);
	int end_x = Max(player_loc.x, professor_loc.x);

	int start_y = Min(player_loc.y, professor_loc.y);
	int end_y = Max(player_loc.y, professor_loc.y);

	int other_count = 0;
	// 교수와 학생의 위치로 네모를 만들어
	for (int y = start_y; y <= end_y; ++y)
	{
		for (int x = start_x; x <= end_x; ++x)
		{
			if (map[y * count + x] == other_student)
			{
				++other_count;
				// 다른학생이 3명 넘으면
				if (other_count >= 3)
				{
					// 통과
					IOHelper::Print(1, 1);
					return 0;
				}
			}
		}
	}

	IOHelper::Print(1, 0);
	return 0;
}