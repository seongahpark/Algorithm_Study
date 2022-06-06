#include <bits/stdc++.h>
using namespace std;

deque<int> GetNums(const string &strNums, int arrSize)
{
    deque<int> nums(arrSize);

    int idx = 0;
    string temp = "";
    for (int i = 1; i < strNums.size() - 1; i++)
    {
        if (strNums[i] == ',')
        {
            nums[idx++] = stoi(temp);
            temp = "";
        }
        else
            temp += strNums[i];
    }

    if (temp.size() > 0)
        nums[idx] = stoi(temp);

    return nums;
}

bool Solve(const string &cmd, deque<int> &nums)
{
    bool reverseFlag = false;

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i] == 'R')
        {
            reverseFlag = reverseFlag ? false : true;
        }
        else if (cmd[i] == 'D')
        {
            if (!nums.empty())
            {
                if (reverseFlag)
                    nums.pop_back();
                else
                    nums.pop_front();
            }
            else
                return true;
        }
    }

    // reverseFlag 가 true 이면 reverse 비용 들게 됨.
    // 살짝 필요없는 오버헤드
    if (reverseFlag)
        reverse(nums.begin(), nums.end());

    return false;
}

void PrintFormat(const deque<int> &nums)
{
    cout << '[';
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
            cout << nums[i];
        else
            cout << nums[i] << ',';
    }
    cout << "]\n";
}

int main()
{
    int T;
    cin >> T;

    string cmd;
    string strNums;
    int arrSize;
    for (int i = 0; i < T; i++)
    {
        cin >> cmd >> arrSize >> strNums;

        // string으로 들어온 숫자 배열을 deque<int>로 변환
        deque<int> nums = GetNums(strNums, arrSize);

        // 명령어들을 수행하고 error가 났으면 errorFlag 는 true
        bool errorFlag = Solve(cmd, nums);

        if (errorFlag)
            cout << "error\n";
        else
            PrintFormat(nums);
    }
}