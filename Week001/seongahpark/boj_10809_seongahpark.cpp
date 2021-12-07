#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	vector<int> v;
	string str;
	
	cin >> str;
	for(int i=0; i<26; i++){
		v.push_back(-1);
	}
	
	for(int i=0; i<str.length(); i++){
		if(str[i] == 'a' && v[0] == -1) v[0] = i;
		else if(str[i] == 'b' && v[1] == -1) v[1] = i;
		else if(str[i] == 'c' && v[2] == -1) v[2] = i; 
		else if(str[i] == 'd' && v[3] == -1) v[3] = i; 
		else if(str[i] == 'e' && v[4] == -1) v[4] = i;
		else if(str[i] == 'f' && v[5] == -1) v[5] = i; 
		else if(str[i] == 'g' && v[6] == -1) v[6] = i; 
		else if(str[i] == 'h' && v[7] == -1) v[7] = i; 
		else if(str[i] == 'i' && v[8] == -1) v[8] = i; 
		else if(str[i] == 'j' && v[9] == -1) v[9] = i; 
		else if(str[i] == 'k' && v[10] == -1) v[10] = i; 
		else if(str[i] == 'l' && v[11] == -1) v[11] = i; 
		else if(str[i] == 'm' && v[12] == -1) v[12] = i; 
		else if(str[i] == 'n' && v[13] == -1) v[13] = i; 
		else if(str[i] == 'o' && v[14] == -1) v[14] = i; 
		else if(str[i] == 'p' && v[15] == -1) v[15] = i; 
		else if(str[i] == 'q' && v[16] == -1) v[16] = i; 
		else if(str[i] == 'r' && v[17] == -1) v[17] = i; 
		else if(str[i] == 's' && v[18] == -1) v[18] = i; 
		else if(str[i] == 't' && v[19] == -1) v[19] = i; 
		else if(str[i] == 'u' && v[20] == -1) v[20] = i; 
		else if(str[i] == 'v' && v[21] == -1) v[21] = i;
		else if(str[i] == 'w' && v[22] == -1) v[22] = i; 
		else if(str[i] == 'x' && v[23] == -1) v[23] = i; 
		else if(str[i] == 'y' && v[24] == -1) v[24] = i; 
		else if(str[i] == 'z' && v[25] == -1) v[25] = i; 
	}
	
	for(int i=0; i<26; i++){
		cout << v[i] << " ";
	}
	return 0;
}
