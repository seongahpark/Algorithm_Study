#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <string>

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
	int row, col;

	IOHelper::Read(0, 1, &col, &row);

	std::map<std::string, int> storage;
	std::vector<std::string> inputs;

	for (int i = 0; i < col; ++i)
	{
		std::string switch_str;
		std::cin >> switch_str;
		inputs.push_back(switch_str);
	}

	int switch_count;
	IOHelper::Read(0, 1, &switch_count);
	bool is_odd_count = (switch_count % 2) == 0;

	for (auto& switch_str : inputs)
	{
		int zero_count = 0;
		// 0의 갯수 찾기
		for (char ch : switch_str)
		{
			if (ch == '0')
				zero_count++;
		}

		bool is_odd_zero_count = zero_count % 2 == 0;

		// 0의 갯수와 스위치를 컨트롤 할 수 있는 갯수가 홀 짝이 같을 경우
		// 0의 갯수를 1로 변환할 수 있을 정도의 스위치 권한이 있다면
		if (zero_count > switch_count || (is_odd_zero_count != is_odd_count))
			continue;

		// 같은 값을 찾아서 증감
		if (storage.find(switch_str) == storage.end())
		{
			storage.insert({ switch_str, 1 });
		}
		else
		{
			storage[switch_str] += 1;
		}
	}

	// 최대값 구하기
	int result = 0;
	for (auto& pair : storage)
	{
		result = MaxFunc(result, pair.second);
	}

	IOHelper::Print(1, result);

	return 0;
}