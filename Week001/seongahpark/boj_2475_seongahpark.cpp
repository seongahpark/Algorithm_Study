#include <iostream>

using namespace std;

int main(){
	int num[5], ans[5], sum=0, res=0;
	for(int i=0; i<5; i++){
		cin >> num[i];
		ans[i] = num[i] * num[i];
		sum += ans[i];
	}
	res = sum%10;
	
	cout << res;
	
	return 0;
}
