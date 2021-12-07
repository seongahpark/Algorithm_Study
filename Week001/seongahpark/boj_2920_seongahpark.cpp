#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	vector<int> c;
	int tmp;
	for(int i=0; i<8; i++){
		cin >> tmp;
		v.push_back(tmp);
		c.push_back(tmp);
	}
	
	if(v[0] == 1){
		sort(v.begin(), v.end());
		if(v == c) cout << "ascending";
		else cout << "mixed";
	}else if(v[0] == 8){
		sort(v.rbegin(), v.rend());
		if(v == c) cout << "descending";
		else cout << "mixed";
	}else cout << "mixed";
	
	return 0;
} 
