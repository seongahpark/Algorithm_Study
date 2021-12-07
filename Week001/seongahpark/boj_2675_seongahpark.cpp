#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	vector<int> nV;
	vector<string> sV;
	int num, tmp;
	string str;
	cin >> num;
	for(int i=0; i<num; i++){
		cin >> tmp;
		cin >> str;
		nV.push_back(tmp);
		sV.push_back(str);
	}
	
	for(int i=0; i<num; i++){
		for(int j=0; j<sV[i].length(); j++){
			for(int z=0; z<nV[i]; z++){
				cout << sV[i][j];
			}
		}
		cout << "\n";
	}
	
	return 0;
}
