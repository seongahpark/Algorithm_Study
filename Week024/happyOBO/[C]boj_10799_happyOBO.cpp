#include <bits/stdc++.h>

using namespace std;


int main(){
	stack<char> s;
	string word;
	int result=0;
	cin >> word;
	for(int i=0; i < word.size();i++){
		if(word[i]=='('){
			s.push('(');
		}
		else{
			// 레이저
			if(word[i-1]=='('){
				s.pop();
				// s 사이즈 : 레이저에 잘리는 막대기 개수
				result += s.size();
			}
			else{
				result +=1;
				s.pop();
			}
		}
	}
	cout << result;
}
