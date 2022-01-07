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