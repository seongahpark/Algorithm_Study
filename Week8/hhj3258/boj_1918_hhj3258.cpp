#include <bits/stdc++.h>
using namespace std;

void Solve(string &equation)
{
    stack<char> operators;
    string answer = "";

    for (int i = 0; i < equation.size(); i++)
    {
        if (equation[i] >= 'A' && equation[i] <= 'Z')
        {
            answer += equation[i];
        }
        else
        {
            if (equation[i] == '(')
            {
                operators.push(equation[i]);
            }
            else if (equation[i] == '+' || equation[i] == '-')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    answer += operators.top();
                    operators.pop();
                }
                operators.push(equation[i]);
            }
            else if (equation[i] == '*' || equation[i] == '/')
            {
                while (!operators.empty() && (operators.top() == '*' || operators.top() == '/'))
                {
                    answer += operators.top();
                    operators.pop();
                }
                operators.push(equation[i]);
            }
            else if (equation[i] == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    answer += operators.top();
                    operators.pop();
                }
                operators.pop();
            }
        }
    }

    while (!operators.empty())
    {
        answer += operators.top();
        operators.pop();
    }

    cout << answer;
}

int main()
{
    string equation;
    cin >> equation;

    Solve(equation);
}