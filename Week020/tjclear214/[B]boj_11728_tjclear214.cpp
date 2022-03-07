#include <iostream>

using namespace std;

int main()
{
	// Variables
	int n = 0, m = 0;
	int aIndex = 0, bIndex = 0;

	// I/O
	cin >> n >> m;

	int* a = new int[n];
	int* b = new int[m];

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);

	// Solution
	while (aIndex < n && bIndex < m)
	{
		if (a[aIndex] < b[bIndex])
		{
			printf("%d ", a[aIndex]);
			aIndex++;
		}
		else
		{
			printf("%d ", b[bIndex]);
			bIndex++;
		}
	}

	if (aIndex < n) for (int i = aIndex; i < n; i++) printf("%d ", a[i]);
	if (bIndex < m) for (int i = bIndex; i < m; i++) printf("%d ", b[i]);

	// Decommissioning
	delete[] a;
	delete[] b;

	return 0;
}