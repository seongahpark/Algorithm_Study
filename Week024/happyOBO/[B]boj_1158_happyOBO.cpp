#include <bits/stdc++.h>

using namespace std;


int main(){
	queue<int> q;
	queue<int> result;
	int N,M;

	cin >> N >> M;

	for(int i=1;i<=N;i++){
		q.push(i);
	}
	while(1){
		if(!q.empty()){
			for(int i=1;i<=M;i++){
				if(i !=M){
					q.push(q.front());
					q.pop();
				}
				else if(i==M){
					result.push(q.front());
					q.pop();
				}
			}
		}
		else
			break;
	}
	cout << "<";
	for(int i=0;i<N-1;i++){
		printf("%d, ",result.front());
		result.pop();
	}
	cout << result.front() << ">";
}