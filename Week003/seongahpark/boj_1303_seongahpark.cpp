#include <iostream>
#include <queue>
#include <string>
#define max 101

using namespace std;

char map[max][max];
bool visited[max][max];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

queue<pair<int, int> > q;

int bfs(int x, int y, char p){
	visited[y][x] = true;
	q.push(make_pair(y, x));
	int power = 1;
	
	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(-1 < nx && nx < n && -1 < ny && ny < m){
				if(map[ny][nx] == p && visited[ny][nx] == 0){
					visited[ny][nx] = true;
					power++;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}
	return power*power;
}

int main(){
	cin >> n >> m;
	int w_power = 0, b_power = 0;
	for(int i=0; i<m; i++){
		cin >> map[i];
	}

	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				if(map[i][j] == 'W') w_power += bfs(j,i,'W');
				else b_power += bfs(j,i,'B');
			}
		}
	}
	
	cout << w_power << " " << b_power;
	
	return 0;
}
