#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;

vector<int> failFunc(string p) {
    int plen = p.length();
    vector<int> failVec(plen, 0);
    int j = 0;
    for (int i = 1; i < plen; i++) {
        while (j > 0 && p[i] != p[j]) {
            j = failVec[j - 1];
        }
        if (p[i] == p[j]) {
            failVec[i] = ++j;
        }
    }
    return failVec;
}

int KMP(string s, string p) {
    vector<int> failVec = failFunc(p);
    int j = 0;

    for (int i = 0; i < s.length(); i++) { //s 길이 기준
        while (j > 0 && s[i] != p[j]) {
            j = failVec[j - 1];
        }
        if (s[i] == p[j]) {
            if (j == p.length() - 1) return 1; //p 길이 기준
            else j += 1;
        }
    }
    return 0;

}

int main() {

    string s, p;
    cin >> s >> p;

    n = s.length();

    cout << KMP(s, p);

    return 0;
}