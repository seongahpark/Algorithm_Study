# 유니온 파인드

CYCLE 만드는 문제에서 유니온 파인드를 많이 사용한다.

### 유니온 파인드란?

그래프 알고리즘의 일종. 상호 배타적 집합, Disjoint-set, 분리 집합이라고도 한다

여러 노드가 존재할 때, 어떤 두 개의 노드를 같은 집합으로 묶어놓고, 다시 어떤 두 노드가 같은 집합에 있는지 확인하는 알고리즘.

1. Find
    
    노드 x가 어느 집합에 포함되어 있는지 찾는 연산
    
2. Union
    
    노드 x가 포함된 집합과 노드 y가 포함된 집합을 합치는 연산
    

### 유니온 파인드 구현

`parent[i]` 를 i 노드의 부모 노드라고 정의하고 초기화해준다.

`parent[i] = i` 인 경우 루트노드 

```cpp
int parent[MAX_SIZE];

for (int i=0; i<MAX_SIZE; i++)
  parent[i] = i;
```

1. **find 함수 구현**

```cpp
int find(int x){
  if (x==parent[x]){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}
```

1. **union 함수 구현**

두 노드가 각 포함되어 있는 집합을 합쳐줘야 하는데, union(x,y)라면 y의 parent를 x로 만들어주는 작업을 할 것이다

```cpp
// rank를 통해 트리의 높이가 낮은 트리가 높은 트리 밑으로 들어가도록 해줌
int rank[MAX_SIZE];

for (int i=0; i<MAX_SIZE; i++)
	rank[i] = 1;

void union(int x, int y){
  x = find(x);
  y = find(y);
  
  if (x == y)
    return;
  
  if (rank[x] > rank[y]){
    parent[y] = x;
    rank[x] += rank[y];
  }
  else {
    parent[x] = y;
    rank[y] += rank[x];
  }
}
```

### ****Weighted Union Find****

parent 배열은 음수일 경우, 부모 노드로서 음수의 절대값은 size가 되고, 양수일 경우에는 부모노드를 가리키게 된다.

ex1) `parent[2] = -3` : 2번 노드 밑에 두 개의 노드가 더 있어 총 세 개의 노드가 존재

ex2) `parent[3] = 5` : 3번 노드의 부모가 5번 노드

```cpp
int parent[MAX_SIZE];

for (int i=0; i<MAX_SIZE; i++)
  parent[i] = -1;

int find(int x){
  if (parent[x] < 0){
    return x;
  }
  else{
    int y = find(parent[x]);
    parent[x] = y;
    return y;
  }
}

void union(int x, int y){
  x = find(x);
  y = find(y);
  
  if (x == y)
    return;
  
  // parent[x], parent[y] 값은 음수이므로 값이 작은 경우가 더 높이가 큰 노드이다.
  if (parent[x] < parent[y]){
    parent[x] += parent[y];
    parent[y] = x;
  }
  else {
    parent[y] += parent[x];
    parent[x] = y;
  }
}
```