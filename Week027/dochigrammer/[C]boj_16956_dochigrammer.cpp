#include <iostream>
#include <vector>
#include <queue>
#include <functional>

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

	template <typename T>
	static void Print(int start_idx, int loop_count, T* arg)
	{
		for (int i = 0; i < loop_count; ++i)
		{
			std::cout << (*(arg + start_idx + i));
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
int Clamp(int val, int min, int max)
{
	if (val < min) return min;
	if (val > max) return max;
	return val;
}

const char sheep = 'S';
const char wolf = 'W';
const char fence = 'D';
const char empty = '.';

int row, col;

char MakeFence(char* world, int x, int y)
{
	x = Clamp(x, 0, row - 1);
	y = Clamp(y, 0, col - 1);

	if (world[y * row + x] == empty)
	{
		world[y * row + x] = fence;
	}

	return world[y * row + x];
}

bool IsSheep(char* world, int x, int y)
{
	return world[y * row + x] == sheep;
}

int main()
{
	IOHelper::Read(0, 1, &col, &row);

	char* world = new char[row * col];

	IOHelper::Read(0, row * col, world);

	// 1차원적 솔루션.
	for (int y = 0; y < col; ++y)
	{
		for (int x = 0; x < row; ++x)
		{
			if (IsSheep(world, x, y)) // 해당 타일에 양이 있다
			{
				// 양이 있으면 주변에 울타리를 세운다.
				// 만약 울타리를 세울 위치에 늑대가 있다면
				if (MakeFence(world, x - 1, y) == wolf ||
					MakeFence(world, x + 1, y) == wolf ||
					MakeFence(world, x, y - 1) == wolf ||
					MakeFence(world, x, y + 1) == wolf)
				{
					delete[] world;

					// 넌 탈락
					IOHelper::Print(1, 0);
					return 0;
				}
			}
		}
	}

	IOHelper::Print(0, 1, 1, "\n");

	for (int y = 0; y < col; ++y)
	{
		IOHelper::Print(0, row, &world[y * row]);
		IOHelper::Print(1, "\n");
	}

	delete[] world;

	return 0;
}
