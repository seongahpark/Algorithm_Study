//#include <bits/stdc++.h>
#include <unordered_map>
#include <stack>
#include <iostream>

int main()
{
    int count = 0;

    std::stack<int> stack;

    std::cin >> count;

    int number = 0;
    for (int i = 0; i < count; ++i)
    {
        std::cin >> number;

        if (number == 0)
        {
            stack.pop();
        }
        else
        {
            stack.push(number);
        }
    }

    int total = 0;
    while (stack.empty() == false)
    {
        total += stack.top();

        stack.pop();
    }

    std::cout << total;

    return 0;
}