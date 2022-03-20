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

		// �ش� ������ ���� ������ ���� �ε����� ����ϸ� �� �� ����.
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

