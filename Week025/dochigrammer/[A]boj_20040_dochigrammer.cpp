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
   int point_num, turn_count;

   std::cin >> point_num >> turn_count;

   int lhs, rhs;

   UnionFinder finder(point_num + 1);
   finder.Initialize();

   int result = 0;
   for (int i = 0; i < turn_count; ++i)
   {
      std::cin >> lhs >> rhs;

      // 사이클이 존재하면( 부모가 같으면 ) 종료
      if (finder.EqualRoot(lhs, rhs))
      {
         result = i + 1;
         break;
      }
      // 계속 결합하면서
      finder.Union(lhs, rhs);
   }

   std::cout << result;

   return 0;
}