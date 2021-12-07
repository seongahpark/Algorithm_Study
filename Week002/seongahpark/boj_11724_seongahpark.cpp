#include <iostream>
#include <vector>
#define max 1001
using namespace std;

//vector< vector<int> > map;
int map[max][max];
bool visited[max];

int cnt = 0;

void dfs(int v, int n){
	visited[v] = 1;
	for(int i=1; i<=n; i++){
		if(map[v][i] == 1 && visited[i] == 0)
			dfs(i, n);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	int a, b;
	
//	vector<int> v;
//	for(int i=0; i<=n+1; i++){
//		for(int j=0; j<=n+1; j++){
//			v.push_back(0);	
//		}
//		map.push_back(v);	
//	}

	for(int i=1; i<=m; i++){
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}	
	
	for(int i=1; i<=n; i++){
		if(visited[i] == 0){
			dfs(i, n);	
			cnt++;
		}
	}	
	cout << cnt;
	return 0;
}
