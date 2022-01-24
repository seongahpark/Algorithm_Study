#include <iostream>
#include <vector>
using namespace std;

typedef struct Node_ {
	char key;
	struct Node_* llink;
	struct Node_* rlink;
}Node;

void preorder(Node* vertex)
{
	if (vertex)
	{
		cout << vertex->key;
		preorder(vertex->llink);
		preorder(vertex->rlink);
	}
}

void inorder(Node* vertex)
{
	if (vertex)
	{
		inorder(vertex->llink);
		cout << vertex->key;
		inorder(vertex->rlink);
	}
}

void postorder(Node* vertex)
{
	if (vertex)
	{
		postorder(vertex->llink);
		postorder(vertex->rlink);
		cout << vertex->key;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<Node> list(N);

	char vertex, left, right;

	for (int i = 0; i < N; i++)
	{
		cin >> vertex >> left >> right;
		list[vertex - 'A'].key = vertex;

		if (left != '.')
		{
			list[vertex - 'A'].llink = &list[left - 'A'];
		}
		else
		{
			list[vertex - 'A'].llink = NULL;
		}

		if (right != '.')
		{
			list[vertex - 'A'].rlink = &list[right - 'A'];
		}
		else
		{
			list[vertex - 'A'].rlink = NULL;
		}
	}
	
	preorder(&list[0]);
	cout << "\n";

	inorder(&list[0]);
	cout << "\n";

	postorder(&list[0]);
	cout << "\n";

	return 0;
}