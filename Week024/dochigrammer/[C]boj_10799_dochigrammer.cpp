#include <stdio.h>

class stack
{
	int top = 0;
	char buffer[50001];

public:
	void push(char v) { buffer[top++] = v; }
	void pop() { --top; }
	int size() const { return top; }
};

int main()
{
	stack stack;

	char input[100001];
	scanf("%s", input);

	int total = 0;
	const char start_bracket = '(';

	int idx = 0;
	char c;
	while ((c = input[idx]) != NULL)
	{
		if (c == start_bracket)
		{
			stack.push(c);
		}
		else
		{
			stack.pop();

			if (input[idx - 1] == start_bracket)
			{
				total += stack.size();
			}
			else
			{
				++total;
			}
		}
		++idx;
	}

	printf("%d", total);

	return 0;
}