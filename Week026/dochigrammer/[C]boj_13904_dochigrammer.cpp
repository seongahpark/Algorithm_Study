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

struct AssignmentInfo
{
public:
    int deadline;
    int score;
};

int main()
{
    const unsigned int MAX_COUNT = 1000;

    auto a = [](int a) {};

    int assignment_count = 0;
    IOHelper::Read(0, 1, &assignment_count);
    
    AssignmentInfo assignment[MAX_COUNT];
    IOHelper::Read(0, assignment_count * 2, &assignment[0].deadline);

    std::sort(assignment, assignment + assignment_count, 
        [](const AssignmentInfo& lhs, const AssignmentInfo& rhs)
        {
            if (lhs.score > rhs.score)
                return true;

            return false;
        });
    

    int score[MAX_COUNT] = { 0 };
    int max_deadline = 0;

    for (int i = 0; i < assignment_count; ++i)
    {
        max_deadline = std::max(max_deadline, assignment[i].deadline);
        
        for (int j = assignment[i].deadline - 1; j >= 0; --j)
        {
            if (score[j] == 0)
            {
                score[j] = assignment[i].score;
                break;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < max_deadline; ++i)
    {
        total += score[i];
    }

    IOHelper::Print(1, total);
        
    return 0;
}