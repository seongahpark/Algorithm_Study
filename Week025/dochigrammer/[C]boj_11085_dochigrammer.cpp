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


struct Path
{
    // 출발지, 도착지, 가중치
   int src;
   int dst;
   int weight;

   bool operator<( const Path& other) const
   {
      return weight < other.weight;
   }

   bool operator>(const Path& other) const
   {
      return weight > other.weight;
   }
};

int main()
{
   int point_count, path_count, source, destination;

   std::cin >> point_count >> path_count;
   std::cin >> source >> destination;

   std::priority_queue<Path> queue;

   // 출발지, 도착지, 가중치
   Path path;

   for (int i = 0; i < path_count; ++i)
   {
      std::cin >> path.src >> path.dst >> path.weight;
      
      // 가중치 기준으로 우선순위 큐에 담음
      queue.push(path);
   }

   UnionFinder finder(point_count);
   finder.Initialize();

   while (queue.empty() == false)
   {
       // 가중치가 높은순서대로 추출
      path = queue.top();
      queue.pop();

      // 갈 수 있는 길 결합
      finder.Union(path.src, path.dst);

      // 출발지에서 목적지로 갈수 있다면 ( 부모가 같다면 )
      if (finder.EqualRoot(source, destination))
      {
         std::cout << path.weight;
         break;
      }
   }

   return 0;
}
