#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

// 삭제 함수
void del_func(deque<int> &nums, bool reverse_flag)
{
    // 역방향인지 체크
    if (!reverse_flag)
        // 정방향이면 앞 원소 삭제
        nums.pop_front();
    else
        // 역방향이면 뒤 원소 삭제
        nums.pop_back();
}

// 출력 함수
void print_func(deque<int> &nums, bool reverse_flag)
{
    cout << '[';
    while (!nums.empty())
    {
        // 정방향이면 앞에서부터 출력
        if (!reverse_flag)
        {
            if (nums.size() > 1)
                cout << nums.front() << ",";
            else
                cout << nums.front();

            nums.pop_front();
        }
        // 역방향이면 뒤에서부터 출력
        else
        {
            if (nums.size() > 1)
                cout << nums.back() << ",";
            else
                cout << nums.back();

            nums.pop_back();
        }
    }
    cout << "]\n";
}

void Solve(string p, int n, string str)
{
    deque<int> nums;

    string num = "";
    // 앞 뒤의 [] 제외하고 반복문 돌리면서 input 받는다
    for (int i = 1; i < str.size() - 1; i++)
    {
        // ',' 만나면 저장해둔 문자열 형식의 num을 deque에 넣어준다
        if (str[i] == ',')
        {
            nums.push_back(stoi(num));
            num = "";
        }
        else
        {
            // 두자리, 세자리 숫자 등이 있으므로 바로 deque에 넣어주지는 않는다.
            num += str[i];
        }
    }
    // input이 0개일 때는 제외해준다
    if (num != "")
        nums.push_back(stoi(num));

    // 역방향은 reverse 함수를 쓰지 않고 flag 변수를 활용한다.
    // reverse 함수는 너무 느리기 때문에
    bool reverse_flag = false;
    for (int i = 0; i < p.size(); i++)
    {
        // R : reverse
        if (p[i] == 'R')
            reverse_flag = reverse_flag ? false : true;
        // D : delete
        else
        {
            // 원소가 없는데 삭제하려고 하면 error 출력 후 return
            if (nums.empty())
            {
                cout << "error\n";
                return;
            }

            del_func(nums, reverse_flag);
        }
    }

    print_func(nums, reverse_flag);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string p;
    int n;
    int num;
    string str;
    for (int t = 0; t < T; t++)
    {
        cin >> p;
        cin >> n;
        cin >> str;

        Solve(p, n, str);
    }
}