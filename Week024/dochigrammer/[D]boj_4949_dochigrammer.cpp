#include <stdio.h>

class stack
{
	const static int MAX_SIZE = 102;
	int top = 0;
	char buffer[MAX_SIZE];

public:
	void push(char v) { buffer[top++] = v; }
	void pop() { --top; }
	int size() const { return top; }
	char get_top() const { return buffer[top - 1]; }
	bool empty() const { return top <= 0; }
	void clear() { top = 0; }
};

int main()
{
	char sz_buf[102];
	stack stack;

	while (true)
	{
		stack.clear();

		fgets(sz_buf, 102, stdin);

		char* ptr = sz_buf;
		char c;
		bool is_balanced = true;

		// 종료 검사
		if ((sz_buf[0] == '.' && sz_buf[1] == '\n'))
			break;

		while ((c = *ptr) != NULL)
		{
			if (c == '(' || c == '[')
			{
				stack.push(c); // 시작하면 스택에 푸시
			}
			else if (c == ')')
			{
				if (stack.empty() || stack.get_top() != '(') // 마지막 괄호가 일치하지 않으면
				{
					is_balanced = false;
					break;
				}
				stack.pop();

			}
			else if (c == ']')
			{
				if (stack.empty() || stack.get_top() != '[') // 마지막 괄호가 일치하지 않으면
				{
					is_balanced = false; 
					break;
				}
				stack.pop();
			}

			ptr++;
		}

		if (stack.size() == 0 && is_balanced)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}