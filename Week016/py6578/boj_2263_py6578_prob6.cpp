#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001
int Index[MAX];
int inorder[MAX];
int postorder[MAX];
int N;

void getPreorder(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
		return;

	int rootIndex = Index[postorder[postEnd]]; // postorder�� �� ���� root��, Indx �迭�� ���� inorder���� root index����
	int leftSize = rootIndex - inStart;
	int rightSize = inEnd - rootIndex;

	cout << inorder[rootIndex] << ' '; // root �� ���

	getPreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
	getPreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> inorder[i];
		Index[inorder[i]] = i; // inorder ��ҵ��� Index ���� ����
	}
	for (int i = 1; i <= N; i++)
		cin >> postorder[i];

	getPreorder(1, N, 1, N);

	return 0;
}
