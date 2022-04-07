#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    stack<char> s;
    string str;
    int res = 0;
    cin >> str;

    // '('를 만날 때는 push, ')'를 만날 때는 pop인데 레이저인지 파이프인지 체크
    for(int i=0; i<str.length(); i++){
        if(str[i] == '(') s.push(str[i]);
        else if(str[i] == ')' && str[i-1] == '('){ // 레이저
            s.pop();
            res += s.size(); // 스택에 쌓여있는 ( 의 개수만큼 더해줌
        }else{ // 닫혀서 잘린 개수 추가
            s.pop();
            res++;
        }
    }

    cout << res;
    return 0;
}