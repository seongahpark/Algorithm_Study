#include <bits/stdc++.h>
using namespace std;

int N;

void Solve(vector<int> &A)
{
    stack<int> my_stack;
    for (int i = 0; i < N; i++)
    {
        while (!my_stack.empty() && A[my_stack.top()] < A[i])
        {
            // 현재 스택 내의 top의 인덱스에 해당하는 오큰수를 찾았다면
            // A 배열을 현재 입력값으로 갱신해주고 pop
            A[my_stack.top()] = A[i];
            my_stack.pop();
        }

        // 다음에 들어올 값을 모르니 일단 push
        my_stack.push(i);
    }

    // 오큰수를 찾지 못한 스택 내의 값들은 모두 -1로 초기화해준다.
    while (!my_stack.empty())
    {
        A[my_stack.top()] = -1;
        my_stack.pop();
    }

    for (int a : A)
        cout << a << ' ';
}

int main()
{
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    Solve(A);
}