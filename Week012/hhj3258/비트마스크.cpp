#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

void BitMask_Exam(int a, int b)
{
    vector<vector<int>> combination;

    // 2^a 만큼 반복
    // a=4 --> 0000 --> 각 자릿수가 1 or 0 인 경우의 수 = 16 = 2^4
    // (1 << a) --> 2진수 1을 왼쪽으로 a 번 시프트 --> a=4이면 0b10000 = 16
    for (int i = 1; i < (1 << a); i++)
    {
        int cnt = 0;
        vector<int> indexs;

        cout << "[i = " << i << "]" << endl;
        cout << bitset<4>(i) << " -> i = " << i << endl;
        for (int j = 0; j < a; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                cout << "[j = " << j << "] " << bitset<4>(1 << j) << " -> (1 << j) = " << (1 << j) << endl;

                indexs.push_back(j);
                cnt++;
            }
        }
        cout << endl;

        // 조합 : a 개 중 b 개 뽑기
        if (cnt == b)
        {
            combination.push_back(indexs);
        }
    }

    cout << "a = " << a << ", ";
    cout << "b = " << b << endl;
    for (int i = 0; i < combination.size(); i++)
    {
        for (int j = 0; j < combination[i].size(); j++)
        {
            cout << combination[i][j] << ' ';
        }
        cout << endl;
    }
}

vector<vector<int>> BitMask_Permutation(int a)
{
    vector<vector<int>> permutation;

    for (int i = 1; i < (1 << a); i++)
    {
        int cnt = 0;
        vector<int> indexs;
        for (int j = 0; j < a; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                indexs.push_back(j);
                cnt++;
            }
        }

        permutation.push_back(indexs);
    }

    return permutation;
}

vector<vector<int>> BitMask_Combination(int a, int b)
{
    vector<vector<int>> combination;

    for (int i = 1; i < (1 << a); i++)
    {
        int cnt = 0;
        vector<int> indexs;

        for (int j = 0; j < a; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                indexs.push_back(j);
                cnt++;
            }
        }

        if (cnt == b)
        {
            combination.push_back(indexs);
        }
    }

    return combination;
}

int main()
{
    int a = 5;
    int b = 3;

    cout << "--------Permutation--------" << endl;
    vector<vector<int>> permutation = BitMask_Permutation(a);
    for (int i = 0; i < permutation.size(); i++)
    {
        for (int j = 0; j < permutation[i].size(); j++)
            cout << permutation[i][j] << ' ';
        cout << endl;
    }

    cout << "--------Combination--------" << endl;
    vector<vector<int>> combination = BitMask_Combination(a, b);
    for (int i = 0; i < combination.size(); i++)
    {
        for (int j = 0; j < combination[i].size(); j++)
            cout << combination[i][j] << ' ';
        cout << endl;
    }
}