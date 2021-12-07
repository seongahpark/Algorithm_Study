#include <iostream>
#include <string>

using namespace std;
int main() {
    string s;
    cin >> s;
    int answer = 0;
    bool minus = false;
    string  temp;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            if (minus)
                answer -= stoi(temp);
            else
                answer += stoi(temp);
            temp = "";
            if (s[i] == '-')
                minus = true;
        }
        else {
            temp += s[i];
        }
    }
    cout << answer;
}