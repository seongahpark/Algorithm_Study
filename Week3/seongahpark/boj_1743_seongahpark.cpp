#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 101
using namespace std;

int n, m, waste;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int,int> > q;

int bfs(int y, int x){
	visited[y][x] = true;
	q.push(make_pair(y, x));
	int size = 1;
	
	while(!q.empty()){
		x = q.front().second;
		y = q.front().first;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(0 < nx && nx <= m && 0 < ny && ny <= n){
				if(map[ny][nx] == 1 && visited[ny][nx] == 0){
					visited[ny][nx] = true;
					size++;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	
	return size;
}

int main(){
	int max_size = 0;
	cin >> n >> m >> waste;
	for(int i=0; i<waste; i++){
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(map[i][j] == 1 && !visited[i][j]){
				max_size = max(max_size, bfs(i,j));
			}
		}
	}
	
	cout << max_size;
	return 0;
}
