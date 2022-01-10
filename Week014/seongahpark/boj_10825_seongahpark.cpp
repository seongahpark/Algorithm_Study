#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
	string name;
	int kor, eng, mat;
};

bool cmp(Student a, Student b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.mat == b.mat) {
				return a.name < b.name;
			}
			else return a.mat > b.mat;
		}
		else return a.eng < b.eng;
	}
	else return a.kor > b.kor;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<Student> s(n);
	for (int i = 0; i < n; i++) cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].mat;
	
	sort(s.begin(), s.end(), cmp);
	for (int i = 0; i < n; i++) cout << s[i].name << "\n";
	return 0;
}