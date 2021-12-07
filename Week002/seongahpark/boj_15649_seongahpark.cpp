#include <iostream>
#define max 9

using namespace std;
int n, m;
int map[max];
bool visited[max];

void dfs(int v){
	if(v == m){
		for(int i=0; i<m; i++){
			cout << map[i] << " ";
		}
		cout << "\n"; //endl ���� �ð��ʰ�.. 
	}else{
		for(int i=1; i<=n; i++){
			if(!visited[i]){
				visited[i] = 1;
				map[v] = i;
				dfs(v+1);
				visited[i]= 0; // ��Ʈ��ŷ 
			}
		}
	}
}
int main(){
	cin >> n >> m;
	dfs(0); 
	return 0;
}
