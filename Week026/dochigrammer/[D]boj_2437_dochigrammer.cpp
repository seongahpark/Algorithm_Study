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
    const unsigned int MAX_COUNT = 1000;

    int count = 0;
    IOHelper::Read(0, 1, &count);

    int weights[MAX_COUNT];
    IOHelper::Read(0, count, weights);

    std::sort(weights, weights + count,
    [](int lhs, int rhs)
    {
        if (lhs < rhs)
            return true;

        return false;
    });

    int total = 0;
    for (int i = 0; i < count; ++i)
    {
        if (total + 1 < weights[i])
            break;

        total += weights[i];
    }

    IOHelper::Print(1, total + 1);
    
    return 0;
}
