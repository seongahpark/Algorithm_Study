#include <iostream>
#include <math.h>
using namespace std;

int N, r, c;
int cnt = 0;
bool isFind = false;

// n=가로 또는 세로 길이
void Solve(int y, int x, int n)
{
    if (y == r && x == c)
    {
        cout << cnt;
        return;
    }

    // r < y + n ==> r 이 현재 사분면의 최대 행(y+n)보다 작고
    // c < x + n ==> c 가 현재 사분면의 최대 열(x+n)보다 작고
    // r >= y    ==> r 이 현재 사분면의 최소 행(y)보다 크거나 같고
    // c >= x    ==> c 가 현재 사분면의 최소 열(x)보다 크거나 같다면
    // 분할(divide) ==> 1,2,3,4 분면 재귀 탐색
    if ((r < y + n) && (c < x + n) &&
        (r >= y) && (c >= x))
    {
        int offset = n / 2;

        // 1사분면
        Solve(y, x, n / 2);
        // 2사분면
        Solve(y, x + offset, n / 2);
        // 3사분면
        Solve(y + offset, x, n / 2);
        // 4사분면
        Solve(y + offset, x + offset, n / 2);
    }
    else
    {
        // ex) 3사분면에 r,c 가 있다면 cnt 출력 후에
        // 4분면 재귀에서 이 부분을 만난다.
        // 하지만 이미 cnt를 출력한 후이므로 문제가 없다.
        cnt += n * n;
    }
}

int main()
{
    cin >> N >> r >> c;

    Solve(0, 0, 1 << N);
}