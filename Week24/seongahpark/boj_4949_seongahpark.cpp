#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(1){
        string str;
        getline(cin, str);
        if(str == ".") break;

        bool flag = true;
        stack<char> s;
        for(int i=0; i<str.length(); i++){
            if(str[i] == '(' || str[i] == '[') s.push(str[i]);
            else if(str[i] == ')'){
                if(s.empty() || s.top() == '[') flag = false;
                else s.pop();
            }else if(str[i] == ']'){
                if(s.empty() || s.top() == '(') flag = false;
                else s.pop();
            }
        }
        if(s.empty() && flag) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}