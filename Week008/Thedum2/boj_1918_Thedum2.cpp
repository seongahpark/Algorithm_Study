#include <iostream>
#include <stack>

using namespace std;

int main()
{	
	stack<char> postfix;
	string infix,result="";
	cin >> infix;

	for (int i = 0; i < infix.length(); i++)
	{
		if ('A'<=infix[i]&& infix[i] <= 'Z')
			result += infix[i];
		else if (infix[i] == '(')
			postfix.push(infix[i]);
		else if (infix[i] == '/' || infix[i] == '*')
		{
			while (!postfix.empty()&&(postfix.top()=='*'||postfix.top()=='/'))
			{
				result += postfix.top();
				postfix.pop();
			}
			postfix.push(infix[i]);
		}
		else if (infix[i] == '+' || infix[i] == '-')
		{
			while (!postfix.empty() && postfix.top()!='(')
			{
				result += postfix.top();
				postfix.pop();
			}
			postfix.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (!postfix.empty()&&postfix.top()!='(')
			{
				result += postfix.top();
				postfix.pop();
			}
			postfix.pop();
		}
	}

	while (!postfix.empty())
	{
		result += postfix.top();
		postfix.pop();
	}

	cout << result << endl;
}