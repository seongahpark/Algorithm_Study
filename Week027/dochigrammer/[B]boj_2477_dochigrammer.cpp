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

int clamp_ring(int val, int min, int max)
{
	if (min > val) return max;
	if (max < val) return min;

	return val;
}

int main()
{
	const static int MAX_SIDE_COUNT = 6;
	int factor = 0;

	std::pair<int, int> input[MAX_SIDE_COUNT];

	IOHelper::Read(0, 1, &factor);
	IOHelper::Read(0, MAX_SIDE_COUNT * 2, &input->first);

	int duplicated_check_flag = 0;
	int duplicated_flag = 0;

	for (int i = 0; i < MAX_SIDE_COUNT; ++i)
	{
		int current_dir_flag = 0x01 << input[i].first;

		if (duplicated_check_flag & current_dir_flag)
		{
			// �ߺ��� �ִ� ������ ���� �־����
			duplicated_flag |= current_dir_flag;
		}
		
		// �ߺ� ���� üũ
		duplicated_check_flag |= current_dir_flag;
	}

	int max_square = 1;
	int min_square = 1;

	duplicated_check_flag = 0;
	for (int i = 0; i < MAX_SIDE_COUNT; ++i)
	{
		int current_dir_flag = 0x01 << input[i].first;

		// ���� ������ �ߺ��� �ƴ϶��
		if ((duplicated_flag & current_dir_flag ) == 0x00)
		{
			// �ߺ��� �ƴ� ������ ���� ���� �ִ� ���簢���� ��
			max_square *= input[i].second;

			// �ִ� ���簢���� ���� ����Ǿ� �ִ� ������ �ּ� ���簢���� ������ ���� ����
			int left = clamp_ring(i - 1, 0, MAX_SIDE_COUNT - 1);
			int right = clamp_ring(i + 1, 0, MAX_SIDE_COUNT - 1);

			duplicated_check_flag |= 0x01 << i;
			duplicated_check_flag |= 0x01 << left;
			duplicated_check_flag |= 0x01 << right;
		}
	}

	int flag = 0x01;
	for (int i = 0; i < MAX_SIDE_COUNT; ++i)
	{
		// �ִ� ���簢���� ���� ����Ǿ����� ���� ���� ���Ͽ� �ּ� ���簢�� �� ���ϱ�
		if ((duplicated_check_flag & (flag << i)) == false)
		{
			min_square *= input[i].second;
		}
	}

	// (�ִ� - �ּ�) == �� ����� ������ ����
	IOHelper::Print(1, (max_square - min_square) * factor);

	return 0;
}