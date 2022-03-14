#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;

void solution(int N, int Addition,int Subtraction,int Multiplication,int Division);
void backtrk(int idx, int Addition,int Subtraction,int Multiplication,int Division, int tmp);

vector<int> numbers;
set<int> result;

int main() {
    int N;
    int Addition, Subtraction, Multiplication, Division;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }
    cin >> Addition >> Subtraction >> Multiplication >> Division;
    solution( N,  Addition, Subtraction, Multiplication, Division);
    return 0;
}


void solution(int N, int Addition,int Subtraction,int Multiplication,int Division)
{
    backtrk(1,Addition,Subtraction,Multiplication,Division,numbers[0]);
    int min = INT_MAX, max = INT_MIN;
    for(auto& r : result)
    {
        if(r < min) min = r;
        if(max < r) max = r;
    }
    cout << max << "\n" << min;
}

void backtrk(int idx, int Addition,int Subtraction,int Multiplication,int Division, int tmp)
{
    if(idx == numbers.size())
        result.insert(tmp);
    if(0 < Addition)
        backtrk(idx+1, Addition - 1, Subtraction, Multiplication, Division, tmp + numbers[idx]);
    if(0 < Subtraction)
        backtrk(idx+1, Addition , Subtraction - 1, Multiplication, Division, tmp - numbers[idx]);
    if(0 < Multiplication)
        backtrk(idx+1, Addition, Subtraction, Multiplication -1, Division, tmp * numbers[idx]);
    if(0 < Division)
        backtrk(idx+1, Addition, Subtraction, Multiplication, Division -1, tmp / numbers[idx]);
}