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

template <typename T>
int MinFunc(T value, T other)
{
	if (value < other) return value;

	return other;
}


template <typename T, typename ... Types>
int MinFunc(T value, T other, Types ... args)
{
	if (value < other)
	{
		return MinFunc(value, args...);
	}

	return MinFunc(other, args...);
}

template <typename T>
int MaxFunc(T value, T other)
{
	if (value < other) return other;

	return value;
}

template <typename T, typename ... Types>
int MaxFunc(T value, T other, Types ... args)
{
	if (value < other)
	{
		return MaxFunc(other, args...);
	}

	return MaxFunc(value, args...);
}

int main()
{
	int test_count;

	IOHelper::Read(0, 1, &test_count);

	int length, unit_count;

	for (int test_idx = 0; test_idx < test_count; ++test_idx)
	{
		IOHelper::Read(0, 1, &length, &unit_count);

		int min_time = 0;
		int max_time = 0;

		for (int i = 0; i < unit_count; ++i)
		{
			int ant_pos = 0;
			IOHelper::Read(0, 1, &ant_pos);

			// 막대기준으로 왼 / 오
			// 최대값과 최소값 구해서
			int min_pos = MinFunc(ant_pos, length - ant_pos);
			int max_pos = MaxFunc(ant_pos, length - ant_pos);

			// 얼마나 걸릴지 최소 , 최대시간으로 대입
			min_time = MaxFunc(min_pos, min_time);
			max_time = MaxFunc(max_pos, max_time);
		}

		// 출력
		IOHelper::Print(1, min_time, " ", max_time, "\n");
	}

	return 0;
}