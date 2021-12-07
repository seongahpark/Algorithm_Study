[출처 : gyoogle] (https://github.com/gyoogle/tech-interview-for-developer/blob/master/Algorithm/DFS%20%26%20BFS.md)
### BFS

> 루트 노드 또는 임의 노드에서 **인접한 노드부터 먼저 탐색**하는 방법

**큐**를 통해 구현한다. (해당 노드의 주변부터 탐색해야하기 때문)

<br>

- 두 노드 사이의 최단 경로를 찾을 때 적합

<img src="https://upload.wikimedia.org/wikipedia/commons/5/5d/Breadth-First-Search-Algorithm.gif" width="300">

##### 시간 복잡도

- 인접 행렬 : O(V^2)
- 인접 리스트 : O(V+E)
