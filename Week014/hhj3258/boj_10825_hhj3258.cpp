#include <bits/stdc++.h>
using namespace std;

struct StudentInfo
{
    string name;
    int score1; // 국어
    int score2; // 영어
    int score3; // 수학
};

bool cmp(StudentInfo a, StudentInfo b)
{
    if (a.score1 == b.score1)
    {
        if (a.score2 == b.score2)
        {
            if (a.score3 == b.score3)
            {
                // 4. 모두 같으면, 이름 사전순
                return a.name < b.name;
            }
            else
            {
                // 3. 국어, 영어 같으면, 수학 내림차순
                return a.score3 > b.score3;
            }
        }
        else
        {
            // 2. 국어 같으면, 영어 오름차순
            return a.score2 < b.score2;
        }
    }
    else
    {
        // 1. 국어 내림차순
        return a.score1 > b.score1;
    }
}

int main()
{
    int N;
    cin >> N;

    vector<StudentInfo> students(N);
    for (int i = 0; i < N; i++)
    {
        cin >> students[i].name >> students[i].score1 >> students[i].score2 >> students[i].score3;
    }

    sort(students.begin(), students.end(), cmp);

    for (int i = 0; i < N; i++)
    {
        cout << students[i].name << '\n';
    }
}