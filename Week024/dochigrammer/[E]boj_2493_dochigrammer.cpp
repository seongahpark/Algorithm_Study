#include <stack>
#include <stdio.h>

int main()
{
	std::stack<std::pair<int, int>> stack;

	int count = 0;
	scanf("%d", &count);

	int height = 0;
	for (int i = 0; i < count; ++i)
	{
		scanf("%d", &height);

		while (stack.empty() == false)
		{
			if (stack.top().first >= height)
			{
				printf("%d ", stack.top().second);
				break;
			}
			else
			{
				stack.pop();
			}
		}

		if (stack.empty())
			printf("0 ");

		stack.push(std::pair<int, int>(height, i + 1));
	}

	return 0;
}