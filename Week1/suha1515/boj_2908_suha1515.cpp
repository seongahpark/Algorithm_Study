#include<iostream>
#include<cmath>
using namespace std;
int main()
{	
	int A=0;
	int B=0;
	cin>>A>>B;
	
	string strA = to_string(A);
	string strB = to_string(B);
	A =0;
	B =0;
	for(int i=0;i<strA.length();++i)
	{
		A += (strA[i] - '0') * pow(10,i);
	}	
	for(int i=0;i<strA.length();++i)
	{
		B += (strB[i] - '0') * pow(10,i);
	}
 	if(A<B)
 		cout<<B;
 	else
 		cout<<A;
 	
	return 0;
}
