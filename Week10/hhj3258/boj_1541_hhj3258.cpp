#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

void Solve(string eq)
{
    string str = "";
    vector<string> vec;
    // 입력으로 주어진 식을 모두 돈다.
    // '-' 를 기준으로 식을 잘라서 vec에 저장해준다.
    for (int i = 0; i < eq.size(); i++)
    {
        if (eq[i] == '-')
        {
            vec.push_back(str);
            str = "";
        }
        else
        {
            str += eq[i];
        }
    }
    // 마지막 식(문자열)까지 vec에 저장해준다.
    vec.push_back(str);

    vector<int> sums(vec.size());
    // vec에 저장된 식의 갯수만큼 돈다.
    // stringstream 을 이용해서 연산자를 제외한 숫자만 뽑아주고 숫자들은 모두 더해준다.
    for (int i = 0; i < vec.size(); i++)
    {
        stringstream stream;
        // stream 에 식 1개를 넣어준다.
        stream.str(vec[i]);

        int num;
        // vec[i]의 끝까지 반복하면서 숫자를 뽑는다.
        while (!stream.eof())
        {
            stream >> num;
            // 뽑은 숫자는 sums[i] 에 더해준다.
            sums[i] += num;
        }

        // 입력으로 주어진 식의 첫 문자는 무조건 숫자이다. => 양수
        // 앞선 for 문에서 '-'를 기준으로 잘라줬으므로 sums[1] ~ sums[vec.size()-1] 은 모두 '-' 를 붙여준다.
        if (i > 0)
            sums[i] *= -1;
    }

    int answer = 0;
    for (int i : sums)
        answer += i;

    cout << answer;
}

int main()
{
    string eq;
    cin >> eq;

    Solve(eq);
}