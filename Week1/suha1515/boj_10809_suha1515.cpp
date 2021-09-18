#include <iostream>
#include <map>
using namespace std;
int main()
{	
	map<char,int> alphabet_order;
	string str;
	cin>>str;
	
	for(int i=0;i<str.length();++i)
	{
		auto find_iter = alphabet_order.find(str[i]);
		if(find_iter == alphabet_order.end())
			alphabet_order[str[i]] = i;
	}
	for(char c= 'a'; c<= 'z';++c)
	{
		auto find_iter = alphabet_order.find(c);
		if(find_iter == alphabet_order.end())
			cout<<"-1"<<' ';
		else
			cout<<alphabet_order[c]<<' ';
	}
 	
	return 0;
}
