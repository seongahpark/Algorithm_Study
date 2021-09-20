#include <iostream>
using namespace std;
int main()
{	
	int total=0;
	for(int i=0;i<5;++i)
	{
		int value = 0;
		cin>>value;
		total += value * value;
	}
	total %=10;
	
	cout<<total;
 	
	return 0;
}
