#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int repeat;
	cin >> repeat;

	for (int i = 0; i < repeat; i++)
	{
		stack<short> BOJstack;
		string cmd;
		cin >> cmd;

		for (int j = 0; j < cmd.length(); j++)
		{
			if (cmd[j] == '(')
				BOJstack.push(1);
			else {
				if (BOJstack.empty()) {
					BOJstack.push(1);
					break;
				}
				else
					BOJstack.pop();
			}
		}

		if (BOJstack.empty())
			cout << "YES" << endl;
		else
			cout<<"NO"<<endl;
	}
}