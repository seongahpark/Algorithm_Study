#include <bits/stdc++.h>
#include <unordered_map>

int main()
{
    int list_count = 0;
    std::cin >> list_count;

    std::unordered_map<std::string, int> storage;

    for (int i = 0; i < list_count; ++i)
    {
        std::string str;

        std::cin >> str;
        storage[std::move(str)] = i;
    }

    int count = 0;
    std::vector<int> cars_in_front;

    for (int i = 0; i < list_count; ++i)
    {
        std::string str;

        std::cin >> str;

        int curr_idx = storage[str];

        int front_count = 0;
        for (auto other_idx : cars_in_front)
        {
            if (other_idx < curr_idx) // is front
            {
                front_count++;
            }
        }

        if (front_count < curr_idx)
        {
            ++count;
        }

        cars_in_front.push_back(curr_idx);
    }

    std::cout << count;

    return 0;
}