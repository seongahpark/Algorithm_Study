#include <iostream>
#include <assert.h>
#include <queue>

class UnionFinder
{
protected:
   int _max_size = 0;
   int* _data = nullptr;

public:
   void Initialize()
   {
      Release();

      if (_max_size > 0 && _data == nullptr)
      {
         _data = new int[_max_size];

         for (int i = 0; i < _max_size; ++i)
         {
            _data[i] = i;
         }
      }
   }

   void Release()
   {
      if (_data != nullptr)
      {
         delete[] _data;
         _data = nullptr;
      }
   }

public:
   UnionFinder(int max_size)
   {
      _max_size = max_size;
   }

   ~UnionFinder()
   {
      Release();
   }

   int Find(int value)
   {
      assert(_max_size > value);

      if (_max_size <= value)
         return -1;

      // 최상위 루트 부모가 자기 자신
      if (_data[value] == value)
      {
         return value;
      }
      // 부모가 있을 경우 부모값 참조
      else
      {
         int top_parent = Find(_data[value]);
         _data[value] = top_parent;

         return top_parent;
      }

      return -1;
   }

   void Union(int lhs, int rhs)
   {
      assert(_max_size > lhs && _max_size > rhs);

      int lhs_parent = Find(lhs);
      int rhs_parent = Find(rhs);

      // 최상위 부모가 다르면
      if (lhs_parent > rhs_parent)
      {
         // 우측으로 결합
         _data[rhs_parent] = lhs_parent;
      }
      else
      {
         // 좌측으로 결합
         _data[lhs_parent] = rhs_parent;
      }
   }

   bool EqualRoot(int lhs, int rhs) { return Find(lhs) == Find(rhs); }
};

int main()
{
   int city_count = 0;
   int plan_count = 0;

   std::cin >> city_count >> plan_count;

   UnionFinder finder(city_count);
   finder.Initialize();

   int is_connected = 0;
   for (int i = 0; i < city_count; ++i)
   {
      for (int j = 0; j < city_count; ++j)
      {
         std::cin >> is_connected;
         // 두 도시가 열결되어있다면 결합
         if (is_connected == 1)
         {
            finder.Union(i, j);
         }
      }
   }

   int src, dst = 0;
   std::cin >> dst;
   is_connected = 1;
   for (int i = 1; i < plan_count; ++i)
   {
      src = dst;
      std::cin >> dst;

      // 요소들이 전부 같은 부모일경우 목적지에 도달할 수 있다.
      // 하나라도 부모가 다르면 불가능
      if (finder.EqualRoot(src - 1, dst - 1) == false)
      {
         is_connected = 0;
         break;
      }
   }

   std::cout << (is_connected == 1 ? "YES" : "NO");

   return 0;
}