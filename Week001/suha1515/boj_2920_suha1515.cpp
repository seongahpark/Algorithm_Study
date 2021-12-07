#include <iostream>
using namespace std;
int main()
{	
	int scales[8];
	
	for(int i=0;i<8;++i)
	{
		int value=0;
		cin>>value;
		scales[i] = value;
	}
	
	bool ascending = true;
	bool descending = true;
	for(int i=0;i<8;++i)
	{
		if(scales[i]!=i+1)
			ascending = false;
		if(scales[i]!= 8-i)
			descending = false;
	}
	
	if(ascending && !descending)
		cout<<"ascending";
	else if(!ascending && descending)
		cout<<"descending";
	else
		cout<<"mixed";
	
	return 0;
}
