#include <iostream>
#include <string>

using namespace std;

int main(){
	int num, sum=0;
	string str;
	cin >> num >> str;
	for(int i=0; i<num; i++){
		sum += str[i]-'0'; // char to int 
	}
	cout << sum;
	return 0;
}
