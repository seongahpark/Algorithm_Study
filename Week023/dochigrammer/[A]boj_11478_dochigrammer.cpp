#include <bits/stdc++.h>

int main()
{
   std::set<std::string> set;
   std::string input;
   std::cin >> input;

   for (int i = 0; i < input.length(); ++i)
   {
      std::string str("");
      for (int j = i; j < input.length(); ++j)
      {
         str += input[j];
         set.insert(str);
      }
   }

   std::cout << set.size();

   return 0;
}