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


int CalcDiff(int lhs, int rhs)
{
   if (lhs > rhs) return lhs - rhs;
   return rhs - lhs;
}

int main()
{
   int test_count, log_num;
   std::vector<int> log_heights;

   IOHelper::Read(0, 1, &test_count);
   for (int test_idx = 0; test_idx < test_count; ++test_idx)
   {
      IOHelper::Read(0, 1, &log_num);

      log_heights.assign(log_num, 0);
      IOHelper::Read(0, log_num, log_heights.data());

      std::sort(log_heights.begin(), log_heights.end());

      int max_diff = 0;
      for (int log_idx = 2; log_idx < log_num; ++log_idx)
      {
         max_diff = std::max(max_diff, CalcDiff(log_heights[log_idx - 2], log_heights[log_idx]));
      }

      IOHelper::Print(1, max_diff, "\n");
   }

   return 0;
}