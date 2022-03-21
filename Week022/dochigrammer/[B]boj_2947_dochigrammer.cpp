#include <stdio.h>

void BullbeSort(int* _arr, int _arr_size)
{
	int temp;

	for (int last_idx = _arr_size - 1; last_idx > 0; --last_idx)
	{
		bool is_success = true;

		for (int idx = 0; idx < last_idx; ++idx) // 전형적인 버블정렬이라 생각합니다.
		{
			if (_arr[idx] > _arr[idx + 1])
			{
				// Swap
				temp = _arr[idx];
				_arr[idx] = _arr[idx + 1];
				_arr[idx + 1] = temp;

				for (int i = 0; i < _arr_size; ++i)
				{
					printf("%d ", _arr[i]);
				}
				printf("\n");

				is_success = false;
			}
		}

		if (is_success) // 불필요한 검사 제거
			break;
	}
}

int main()
{
	const int arr_size = 5;

	int blocks[arr_size];

	for (int idx = 0; idx < arr_size; ++idx)
	{
		scanf("%d", &blocks[idx]);
	}

	BullbeSort(blocks, arr_size);
}