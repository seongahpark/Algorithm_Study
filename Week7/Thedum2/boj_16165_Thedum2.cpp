#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, string> GirlGroup;

int main() {
	ios::sync_with_stdio(false); 
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	string GroupName;
	int Membercnt;
	string MemberName;

	for (int i = 0; i < N; i++){
		cin >> GroupName;
		cin >> Membercnt;
		for (int j = 0; j < Membercnt; j++){
			cin >> MemberName;
			GirlGroup.insert({ MemberName, GroupName });
		}
	}

	for (int i = 0; i < M; i++){
		string Problem;
		int Quiz;

		cin >> Problem >> Quiz;
		if (Quiz == 1)
			cout << GirlGroup[Problem] << "\n";
		else {
			for (auto A : GirlGroup)
				if (A.second == Problem)
					cout << A.first << "\n";
		}

	}
}