# 문제
---
## [1493 - 박스 채우기](https://www.acmicpc.net/problem/1493)

</br>

# 풀이

## 알고리즘
---
1. 박스의 length, width, height를 입력받는다.

2. 크기에 따른 큐브와 해당 갯수를 입력받는다.
입력받을 때 큐브의 길이도 구하여 배열에 같이 넣어주자.
(큐브의 길이는 후술할 박스의 길이와 대소비교를 위해서 필요하다.)
```cpp
    // 큐브의 종류, 현재 큐브의 갯수
    int cube_idx, cube_cnt;
    for (int i = 0; i < N; i++)
    {
        cin >> cube_idx >> cube_cnt;

        // CubeInfo { length(큐브의 길이), cnt(큐브의 갯수) }
        CubeInfo cubeInfo;
        // 큐브의 한 변의 길이 = 2^cube_idx
        cubeInfo.length = (1 << cube_idx);
        cubeInfo.cnt = cube_cnt;

        cubes.push_back(cubeInfo);
    }
```

3. 이 문제는 그리디와 분할정복 두 가지 알고리즘을 요구한다.
문제의 큰 줄기는 아래와 같다.
   1. 박스에는 입력받은 큐브들 중 박스에 들어갈 수 있는 가장 큰 큐브부터 먼저 넣어준다. 
-> 그리디
   2. 박스는 큐브를 하나 넣어줄 때마다 큐브를 뺀 3개의 공간으로 분할한 후 a를 수행한다. 
   -> 분할정복

4. 본격적인 알고리즘은 이제부터 그림과 같이 설명하겠다.
검정색은 문제의 박스, 빨간색은 넣을 수 있는 가장 큰 큐브이다.
보라, 초록, 파랑은 각각 분할된 3개의 작은 박스이다.

   1. 박스의 가로 = L, 세로 = W, 높이 = H 이다.
   2. 현재 박스에 넣을 수 있는 가장 큰 큐브를 넣는다.
      입력받을 큐브는 정육면체이므로 큐브의 한 변의 길이 = a 라고 하자.
![](https://images.velog.io/images/hhj3258/post/2ea01bcd-0e6c-469a-a443-3ea20a3f4d1a/image.png)


   3. 위에서 그리디하게 박스를 넣었으므로 이제 분할을 수행하자. 위에서 넣은 큐브를 뺀 공간을 3개의 작은 박스로 나누어줄 수 있다.
(각 보라색, 초록색, 파란색 박스)
이렇게 했을 때 각 박스의 가로, 세로, 높이는 아래와 같이 구해줄 수 있다.
![](https://images.velog.io/images/hhj3258/post/44cdd744-9ecf-4b50-8e96-a2d6bfc2b0da/image.png)
(3개의 공간에서 각각 다시 큐브를 넣어보고, 3개의 공간으로 분할하고.... 재귀적으로 분할정복해준다. 이 과정은 가장 작은 문제를 만날 때까지 반복된다. 그것이 분할정복이니까...)
```cpp
	// a => cubes[i].length
        // 박스를 작은 박스들 3개의 공간으로 나누어 '분할' 한다.
        // Solve(큐브 길이, 박스 세로 - 큐브 길이, 큐브 길이, 현재 큐브 idx)
        Solve(cubes[i].length, width - cubes[i].length, cubes[i].length, i);
        // Solve(박스 가로 - 큐브 길이, 박스 세로, 큐브 길이, 현재 큐브 idx)
        Solve(length - cubes[i].length, width, cubes[i].length, i);
        // Solve(박스 가로, 박스 세로, 박스 높이 - 큐브 길이, 현재 큐브 idx)
        Solve(length, width, height - cubes[i].length, i);
```


5. 전체적인 문제의 줄기는 위와 같다. 이제는 예외 조건만 추가해주면 끝이다.
예외 조건에 대한 설명은 아래 주석 코드에 같이 첨부하겠다.
```cpp
    int answer = 0;
    bool isFail = false;

    void Solve(int length, int width, int height, int idx)
    {
        if (length == 0 || width == 0 || height == 0)
            return;

        for (int i = idx; i >= 0; i--)
        {
            if (cubes[i].cnt <= 0)
                continue;

            if (length < cubes[i].length || width < cubes[i].length || height < cubes[i].length)
                continue;

            cubes[i].cnt--;
            answer++;

            Solve(cubes[i].length, width - cubes[i].length, cubes[i].length, i);
            Solve(length - cubes[i].length, width, cubes[i].length, i);
            Solve(length, width, height - cubes[i].length, i);

            return;
        }

        isFail = true;
    }
```

</br>

## 코드
---
```cpp
#include <iostream>
#include <vector>

using namespace std;

struct CubeInfo
{
    int length = 0;
    int cnt = 0;
};

vector<CubeInfo> cubes;

int answer = 0;
bool isFail = false;

void Solve(int length, int width, int height, int idx)
{
    if (length == 0 || width == 0 || height == 0)
        return;

    for (int i = idx; i >= 0; i--)
    {
        if (cubes[i].cnt <= 0)
            continue;

        if (length < cubes[i].length || width < cubes[i].length || height < cubes[i].length)
            continue;

        cubes[i].cnt--;
        answer++;

        Solve(cubes[i].length, width - cubes[i].length, cubes[i].length, i);
        Solve(length - cubes[i].length, width, cubes[i].length, i);
        Solve(length, width, height - cubes[i].length, i);

        return;
    }

    isFail = true;
}

int main()
{
    int length, width, height;
    cin >> length >> width >> height;

    int N;
    cin >> N;

    int cube_idx, cube_cnt;
    for (int i = 0; i < N; i++)
    {
        cin >> cube_idx >> cube_cnt;

        CubeInfo cubeInfo;
        // 큐브의 한 변의 길이 = 2^cube_idx
        cubeInfo.length = (1 << cube_idx);
        cubeInfo.cnt = cube_cnt;

        cubes.push_back(cubeInfo);
    }

    Solve(length, width, height, N - 1);

    if (isFail)
        cout << "-1";
    else
        cout << answer;
}
```

</br>

## 주석코드
---
```cpp
#include <iostream>
#include <vector>

using namespace std;

struct CubeInfo
{
    int length = 0;
    int cnt = 0;
};

vector<CubeInfo> cubes;

// 채우는데 사용한 큐브의 갯수
int answer = 0;
// 박스를 모두 채웠는지 체크할 bool 변수
bool isFail = false;

// Solve(박스의 가로, 박스의 세로, 박스의 높이, 큐브 배열 시작 인덱스)
void Solve(int length, int width, int height, int idx)
{
    // 종료 조건
    // 박스의 가로, 세로, 높이 중 하나라도 0 이라면 반환
    // 셋 중 하나라도 0이면 부피 = 0 이므로 큐브를 넣을 수 없다
    if (length == 0 || width == 0 || height == 0)
        return;

    // 가장 큰 큐브부터 가장 작은 큐브까지 반복
    for (int i = idx; i >= 0; i--)
    {
        // 현재 큐브의 갯수가 0 이라면 continue
        if (cubes[i].cnt <= 0)
            continue;

        // 박스의 가로, 세로, 높이 중 하나라도 현재 큐브의 길이보다 작다면 continue
        // 셋 중 하나라도 큐브의 길이보다 작다면 큐브를 넣을 수 없다.
        if (length < cubes[i].length || width < cubes[i].length || height < cubes[i].length)
            continue;

        // 여기부터 아래는 큐브를 넣었을 때의 경우

        // 현재 큐브 갯수를 -1
        cubes[i].cnt--;
        // 사용한 큐브 갯수를 +1
        answer++;

        // 박스를 작은 박스들 3개의 공간으로 나누어 '분할' 한다.
        // Solve(큐브 길이, 박스 세로 - 큐브 길이, 큐브 길이, 현재 큐브 idx)
        Solve(cubes[i].length, width - cubes[i].length, cubes[i].length, i);
        // Solve(박스 가로 - 큐브 길이, 박스 세로, 큐브 길이, 현재 큐브 idx)
        Solve(length - cubes[i].length, width, cubes[i].length, i);
        // Solve(박스 가로, 박스 세로, 박스 높이 - 큐브 길이, 현재 큐브 idx)
        Solve(length, width, height - cubes[i].length, i);

        // 박스를 분할하고 작업을 마쳤으므로 반환
        // 반환하지 않으면 작은 큐브들을 현재 박스에 박스가 비어있다고 보고
        // 처음부터 넣는 작업을 반복하게 될 것임.
        return;
    }

    // 만약 현재 재귀에서 박스에 맞는 큐브를 하나도 발견하지 못했다면
    // 박스를 모두 채우지 못했다고 체크
    isFail = true;
}

int main()
{
    int length, width, height;
    // 채우고자 하는 박스의
    // 가로>>세로>>높이
    cin >> length >> width >> height;

    int N;
    // 큐브의 종류의 갯수
    cin >> N;

    // 큐브의 종류, 현재 큐브의 갯수
    int cube_idx, cube_cnt;
    for (int i = 0; i < N; i++)
    {
        cin >> cube_idx >> cube_cnt;

        // CubeInfo { length(큐브의 길이), cnt(큐브의 갯수) }
        CubeInfo cubeInfo;
        // 큐브의 한 변의 길이 = 2^cube_idx
        cubeInfo.length = (1 << cube_idx);
        cubeInfo.cnt = cube_cnt;

        cubes.push_back(cubeInfo);
    }

    // Solve(박스의 가로, 박스의 세로, 박스의 높이, 큐브 배열 시작 인덱스)
    Solve(length, width, height, N - 1);

    if (isFail)
        cout << "-1";
    else
        cout << answer;
}
```

# 여담(주의할 점?)
박스와 큐브 간에 현재 박스에 큐브가 들어갈 수 있는지의 판단을 부피를 통해서 비교해선 안된다. 큐브의 부피가 박스보다 작다고해서 들어갈 수 있는 것은 아니다. 
why? 큐브의 가로가 박스의 가로보다 길 수도 있으니까.
그러므로 해당 문제에서는 박스의 각 길이와 큐브의 각 길이를 비교한 후에 큐브를 넣는 식으로 진행해야 한다.

박스를 3개의 작은 박스로 분할할 때에 꼭 필자와 똑같이 잘라줄 필요는 없다. 사람에 따라서는 빨간색 큐브를 다른 쪽에 넣어볼 수도 있는 거니까. 편한대로 하면 된다.

다른 블로그들을 참고하고 풀 때 설명이 너무 간략해서 이해하는데에 애를 먹어 주석에 좀 더 공을 들이며 쓰도록 노력했다. 
부족한 부분은 댓글을 달아주시면 추가하겠습니다.