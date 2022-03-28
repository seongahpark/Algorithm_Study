#include <bits/stdc++.h>
#include <unordered_map>

int main()
{
   int available_count = 0, list_count = 0;
   std::cin >> available_count;
   std::cin >> list_count;

   std::unordered_map<std::string, int> storage;

   for (int i = 0; i < list_count; ++i)
   {
      std::string str;

      std::cin >> str;
      storage[std::move(str)] =  i;
   }

   std::vector<std::pair<int, std::string>> v(storage.size());
   //std::vector<std::pair<int, std::string>> v;


   int count = 0;

   auto data = v.data();
   for (auto pair : storage)
   {
      data[count++] = { pair.second, pair.first };
   //   v.push_back({ pair.second, pair.first });
   }

   std::sort(v.begin(), v.end());

   count = 0;
   for( auto iter : v)
   {
      if (count >= available_count)
      {
         break;
      }

      std::cout << iter.second << '\n';

      ++count;
   }

   return 0;
}