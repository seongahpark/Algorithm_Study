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


struct PartyInfo
{
   static const unsigned int MAX_PEOPLE = 50;
   int people[MAX_PEOPLE] = { 0 };

   int people_count = 0;

   void AddPerson( int person)
   {
      people[people_count++] = person;
   }
};
   
int main()
{
   int people_count, party, except_people_count;

   std::cin >> people_count >> party >> except_people_count;

   UnionFinder finder(people_count);
   finder.Initialize();

   std::vector<int> except_people;
   for (int i = 0; i < except_people_count; ++i)
   {
      int index;
      std::cin >> index;
      --index;

      except_people.push_back(index);
      // 진실을 말할 수 없는 사람들로 구성된 집합 생성
      finder.Union(except_people[0], index);
   }

   std::vector<PartyInfo> party_infos;

   int party_people_count = 0;
   for (int i = 0; i < party; ++i)
   {
      std::cin >> party_people_count;

      PartyInfo info;
      for (int j = 0; j < party_people_count; ++j)
      {
         int index;
         std::cin >> index;
         --index;

         info.AddPerson(index);
         // 해당 파티의 사람들끼리 결합
         finder.Union(info.people[0], index);
      }

      party_infos.push_back(info);
   }

   // 모두에게 말할수 있다면 모든 파티에서 말할 수 있음
   if (except_people_count == 0)
   {
      std::cout << party;
      return 0;
   }


   int lied_count = 0;
   for (auto info : party_infos)
   {
      bool be_liar = true;
      for (int i = 0; i < info.people_count; ++i)
      {
          // 해당 파티의 사람 중 진실을 알고 있는 집합에 속해있으면 ( 부모가 같다면! )
         if (finder.EqualRoot(except_people[0], info.people[i]))
         {
             // 이번 파티는 포기
            be_liar = false;
            break;
         }
      }

      if (be_liar)
          lied_count++;
   }

   std::cout << lied_count;

   return 0;
}