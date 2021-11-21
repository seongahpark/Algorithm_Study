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
            // ���� ���� ���� top�� �ε����� �ش��ϴ� ��ū���� ã�Ҵٸ�
            // A �迭�� ���� �Է°����� �������ְ� pop
            A[my_stack.top()] = A[i];
            my_stack.pop();
        }

        // ������ ���� ���� �𸣴� �ϴ� push
        my_stack.push(i);
    }

    // ��ū���� ã�� ���� ���� ���� ������ ��� -1�� �ʱ�ȭ���ش�.
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