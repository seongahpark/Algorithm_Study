#include <iostream>
#include <queue>
#include <string>
#define max 101
using namespace std;

char map[max][max];
bool visited[max][max];
int length[max][max];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt = 0;
int n, m;
queue<int> q;

void bfs(){
	visited[0][0] = true;
	cnt++;
	
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(-1 < nx && nx < n && -1 < ny && ny < m){
				if(map[nx][ny] == '1' && visited[nx][ny] == 0){
					cnt++;
					visited[nx][ny] = true;
					length[nx][ny] = length[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		
	}
	
	cout << length[n-1][m-1]+1;
}
int main(){
	cin >> n >> m;

	for(int i=0; i<n; i++){
		string str;
		cin >> str;
		for(int j=0; j<m; j++){
			map[i][j] = str[j];
		}
	}
	
	bfs();
	
	return 0;
}
