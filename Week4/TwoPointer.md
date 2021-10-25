# 투포인터 (Two Pointers)

- 리스트에 순차적으로 접근해야 할 때 두 개의 점의 위치를 기록하면서 처리하는 알고리즘
- ex) 1차원 배열이 있고 이 배열에서 각자 다른 원소를 가리키고 있는 2개의 포인터를 조작해가면서 원하는 것을 얻는 형태이다. 이 때문에 투 포인터 알고리즘이라고 부른다.
- 정렬되어있는 두 리스트의 합집합에도 사용된다. 병합정렬(merge sort)의 counquer 영역의 기초가 되기도 한다.

# 예제 문제

## [11728 - 배열 합치기](https://www.acmicpc.net/problem/11728)

# 알고리즘

- 배열 A의 현재 인덱스를 가리키는 ptrA
- 배열 B의 현재 인덱스를 가리키는 ptrB
- 배열 answer의 현재 인덱스를 가리키는 idx
1. 배열 A와 배열 B를 각각 정렬
2. ```while(ptrA < N && ptrB < M)```
   - ```A[ptrA] < B[ptrB]``` 라면 ```answer[idx]```에 ```A[ptrA]```를 넣어주고 ```idx+1, ptrA+1```
   - ```A[ptrA] >= B[ptrB]``` 라면 ```answer[idx]```에 ```B[ptrB]```를 넣어주고 ```idx+1, ptrB+1```

3. ```while(ptrA < N)``` (배열 A의 탐색을 모두 끝마치지 못했다면)
   - 배열 A의 나머지 값을 모두 answer에 넣어준다

4. ```while(ptrB < N)``` (배열 B의 탐색을 모두 끝마치지 못했다면)
   - 배열 B의 나머지 값을 모두 answer에 넣어준다

1) 초기 설정
- ptrA=0, ptrB=0, idx=0이고 배열 A의 크기=5, 배열 B의 크기=3, 배열 answer의 크기=5+3=8
![](https://images.velog.io/images/hhj3258/post/3eb4cb92-0b33-4c15-8eff-22a051cb084d/image.png)
2) ```A[ptrA]<B[ptrB]``` 이므로 answer에 A[ptrA]를 넣어주고 ```ptrA+1, idx+1```
![](https://images.velog.io/images/hhj3258/post/9b8529db-d6f0-4220-a1a9-d702f0b98c72/image.png)
3) ```A[ptrA]>=B[ptrB]``` 이므로 answer에 B[ptrB]를 넣어주고 ```ptrB+1, idx+1```
![](https://images.velog.io/images/hhj3258/post/083dfd79-1e49-482e-bc14-18a7783e3813/image.png)
4) ```A[ptrA]<B[ptrB]``` 이므로 answer에 A[ptrA]를 넣어주고 ```ptrA+1, idx+1```
![](https://images.velog.io/images/hhj3258/post/8a140e56-c230-4b38-abf8-b2a60128c250/image.png)
5) ```A[ptrA]>=B[ptrB]``` 이므로 answer에 B[ptrB]를 넣어주고 ```ptrB+1, idx+1```
![](https://images.velog.io/images/hhj3258/post/ec7f738f-c28a-4a92-8126-3560a5275dd6/image.png)
6) ```A[ptrA]>=B[ptrB]``` 이므로 answer에 B[ptrB]를 넣어주고 ```ptrB+1, idx+1```
![](https://images.velog.io/images/hhj3258/post/881a8e59-2c73-41c3-81a8-17de844fcdb8/image.png)
7) 위에서 ptrB가 배열 B의 탐색을 모두 마쳤으므로 ptrA가 가리키는 배열 A의 값부터 나머지 값을 모두 answer에 넣어준다.
![](https://images.velog.io/images/hhj3258/post/01a02676-6a17-4d2f-92c1-76cae6e2d373/image.png)

# 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;

void TwoPointer(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ptrA = 0;
    int ptrB = 0;

    vector<int> answer(N + M);
    int idx = 0;
    while (ptrA < N && ptrB < M)
    {
        if (A[ptrA] < B[ptrB])
        {
            answer[idx++] = A[ptrA];
            ptrA++;
        }
        else
        {
            answer[idx++] = B[ptrB];
            ptrB++;
        }
    }

    while (ptrA < N)
        answer[idx++] = A[ptrA++];
    while (ptrB < M)
        answer[idx++] = B[ptrB++];

    for (int i : answer)
        cout << i << ' ';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    TwoPointer(A, B);
}
```

# 주석코드

```cpp
#include <bits/stdc++.h>
using namespace std;

int N, M;

void TwoPointer(vector<int> &A, vector<int> &B)
{
    // 배열 A와 B 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ptrA = 0; // 배열 A 포인터
    int ptrB = 0; // 배열 B 포인터

    // answer: A배열과 B배열을 합쳐줄 배열
    vector<int> answer(N + M);
    // 배열 answer 포인터(인덱스로 봐도 무방함)
    int idx = 0;

    //배열 A 포인터가 N보다 작고 배열 B 포인터가 M보다 작을 때까지 반복
    while (ptrA < N && ptrB < M)
    {
        // A의 포인터의 값이 B의 포인터의 값보다 작다면
        if (A[ptrA] < B[ptrB])
        {
            // A 포인터의 값을 넣어준다
            answer[idx++] = A[ptrA];
            // A 포인터 + 1
            ptrA++;
        }
        // 그 외의 경우
        else
        {
            // B 포인터의 값을 넣어준다
            answer[idx++] = B[ptrB];
            // B 포인터 + 1
            ptrB++;
        }
    }

    // A 배열을 모두 탐색하지 못했다면
    while (ptrA < N)
        // A 배열의 값을 모두 넣어준다
        answer[idx++] = A[ptrA++];

    // B 배열을 모두 탐색하지 못했다면
    while (ptrB < M)
        // B 배열의 값을 모두 넣어준다
        answer[idx++] = B[ptrB++];

    for (int i : answer)
        cout << i << ' ';
}

int main()
{
    // 입력 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 배열 A 크기 >> 배열 B 크기
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    TwoPointer(A, B);
}
```
<br>
---
<br>
## 세그먼트 트리

11659번과 비슷한 유형은 세그먼트 트리로도 풀이가 가능하다.

[세그먼트 트리](https://m.blog.naver.com/ndb796/221282210534)

