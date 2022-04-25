#include <iostream>
#include <vector>

class IOHelper
{
protected:
    template <typename T>
    static void Read_Internal(int start_idx, int loop_count, T* arg)
    {
        for (int i = 0; i < loop_count; ++i)
        {
            std::cin >> (*(arg + start_idx + i));
        }
    }
public:
    template <typename T>
    static void Read(int start_idx, int loop_count, T* arg)
    {
        Read_Internal(start_idx, loop_count, arg);
    }

    template <typename T, typename ... Types>
    static void Read(int start_idx, int loop_count, T* arg, Types* ... args)
    {
        for (int i = 0; i < loop_count; ++i)
        {
            Read_Internal(i, 1, arg);
            Read(i, 1, args...);
        }
    }

    template <typename Proc>
    static void Read(int loop_count, Proc add_proc)
    {
        int value;
        for (int i = 0; i < loop_count; ++i)
        {
            std::cin >> value;
            add_proc(value);
        }
    }

    template <typename T>
    static void Print(int loop_count, T arg)
    {
        std::cout << (arg);
    }

    template <typename T, typename ... Types>
    static void Print(int loop_count, T arg, Types ... args)
    {
        Print(loop_count, arg);
        Print(loop_count, args...);
    }
};

int main()
{
    int count;

    IOHelper::Read(0, 1, &count);

    if (count <= 1)
    {
        IOHelper::Print(1, 0);
        return 0;
    }

    std::priority_queue<int, std::vector<int>, std::greater<int>> queue;

    IOHelper::Read(count, [&](int val) {queue.push(val); });

    int result = 0;
    while (queue.empty() == false)
    {
        int lhs = queue.top();
        queue.pop();

        int rhs = queue.top();
        queue.pop();

        result += (lhs + rhs);

        if (queue.empty())
            break;

        queue.push(lhs + rhs);
    }

    IOHelper::Print(1, result);

    return 0;
}