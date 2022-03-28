#include <bits/stdc++.h>
#include <unordered_map>

struct Priorities
{
public:
   int count = 0;
   int min_idx = INT_MAX;
   int num = 0;

   void IncreaseCount( int _idx )
   {
      count++;

      if (min_idx > _idx)
      {
         min_idx = _idx;
      }

   }

   bool operator<(const Priorities& _other) const
   {
      if (count > _other.count)
      {
         return true;
      }
      else if (count == _other.count)
      {
         return min_idx < _other.min_idx;
      }

      return false;
   }

};

int main()
{
   int count = 0, max = 0;
   std::cin >> count;
   std::cin >> max;

   std::unordered_map<int, Priorities> storage;

   int num = 0;

   for (int i = 0; i < count; ++i)
   {
      std::cin >> num;

      storage[num].IncreaseCount( i );
   }

   std::set<Priorities> set;

   for (auto pair : storage)
   {
      pair.second.num = pair.first;

      set.insert(pair.second);
   }

   for (const auto priorities : set)
   {
      for (int i = 0; i < priorities.count; ++i)
      {
         printf("%d ", priorities.num);
      }
   }

   return 0;
}