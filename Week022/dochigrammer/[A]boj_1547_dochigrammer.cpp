#include <stdio.h>

int main()
{
	const int max_simulation_count = 50;

	int ball_idx = 1;
	int simulation_count = 0;

	scanf("%d", &simulation_count);

	if (simulation_count <= 0 || simulation_count > max_simulation_count) // assertion
		return 0;

	int lhs, rhs;
	for (int curr_count = 0; curr_count < simulation_count; ++curr_count)
	{
		scanf("%d %d" , &lhs, &rhs);

		// 해당 문제는 공을 보유한 컵의 인덱스만 기억하면 될 것 같다.
		if (lhs == ball_idx)
		{
			ball_idx = rhs;
		}
		else if (rhs == ball_idx)
		{
			ball_idx = lhs;
		}
	}

	printf("%d", ball_idx);
	return 0;
}

