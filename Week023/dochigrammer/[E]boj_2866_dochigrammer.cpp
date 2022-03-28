#include <bits/stdc++.h>
#include <unordered_map>

bool IsOverlapped( std::vector<std::string>& table, int start, int end, int col)
{
    std::set<std::string> set;

    for (int x = 0; x < col; ++x)
    {
        std::string str = "";
        for (int y = start; y <= end; ++y)
        {
            char c = table[y][x];

            str += c;
        }

        if (set.insert(std::move(str)).second == false)
        {
            return true;
        }
    }

    return false;
}

int Serach(std::vector<std::string>& table, int start, int end, int col)
{
    int mid = (start + end) / 2;

    if (start > end)
        return mid;

    if (IsOverlapped(table, mid, table.size() - 1, col))
    {
        return Serach(table, start, mid - 1);
    }
    else
    {
        return Serach(table, mid + 1, end);
    }

}

int main()
{
    int row = 0, col = 0;

    std::cin >> row >> col;
    std::vector<std::string> table(row);

    for (int y = 0; y < row; ++y)
    {
        std::string str;
        std::cin >> str;

        table[y] = std::move(str);
    }
    
    int count = Serach(table, 0, row - 1, col);

    std::cout << count;

    return 0;
}