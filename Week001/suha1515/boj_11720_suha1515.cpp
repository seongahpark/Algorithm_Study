#include<iostream>
using namespace std;
int main()
{	
	int numberCount=0;
	int totalSum=0;
	cin>>numberCount;
	string numbers;
	cin>> numbers;
	for(int i=0;i<numberCount;++i)
	{
		int temp= numbers[i] - '0';
		totalSum+=temp;
	}
	cout<<totalSum;
 	
	return 0;
}
