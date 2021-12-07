#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int num, goal, temp;
	int answer = 0;

	cin >> num >> goal;

	vector<int> change;
	
	for(int i=0; i<num; i++)
	{
		cin >> temp;
		change.push_back(temp);
	}

	while (num--)
	{
		if (change[num] <= goal)
		{
			answer += goal / change[num];
			goal = goal % change[num];

		}
	}

	cout << answer << "\n";
	
	return 0;
}