#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int r, c;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int arr[101][101];
int dist[101][101];

queue<pair<int, int> > pq;

int dijkstra(){
	pq.push({0, 0});
	dist[0][0] = 0;

	while(!pq.empty()){
		int x = pq.front().first;
		int y = pq.front().second;

		pq.pop();
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
			if(arr[nx][ny]){
				if(dist[nx][ny] > dist[x][y] + 1){
					dist[nx][ny] = dist[x][y] + 1;
					pq.push({nx, ny});
				}
			}else {
				if(dist[nx][ny] > dist[x][y]){
					dist[nx][ny] = dist[x][y];
					pq.push({nx, ny});
				}
			}
		}
	}

	return dist[r-1][c-1];
}

int main(){
	cin >> c >> r;

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> arr[i][j];
		}
	}

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			dist[i][j] = INT_MAX;
		}
	}

	cout << dijkstra();

	return 0;
}