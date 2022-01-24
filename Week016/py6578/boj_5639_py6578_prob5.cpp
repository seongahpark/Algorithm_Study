#include <iostream>
using namespace std;

int tree[10001];

void postorder(int start, int end) 
{
	if (start >= end) 
		return;

	int mid = start + 1; // start는 subtree의 vertex이다.

	while (mid < end && tree[mid] < tree[start])  // 부모노드보다 커야 right child
	{
		mid++;
	}

	postorder(start + 1, mid); 
	postorder(mid, end);

	
	cout << tree[start] << "\n";
	return;

}

int main() {
	int n = 0;
	int temp;

	while (!cin.eof())
	{
		cin >> temp;
		tree[n++] = temp;
	}

	postorder(0, n-1);

	return 0;
}