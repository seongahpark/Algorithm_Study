#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <map>

using namespace std;
void solution();
void preOrder(int NodeIdx);
void inOrder(int NodeIdx);
void postOrder(int NodeIdx);

pair<int, int> graph[27];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char V, left, right;
        cin >> V >> left >> right;
        graph[V - 'A'].first = left - 'A';
        graph[V - 'A'].second = right - 'A';
    }
    solution();
}

void solution( )
{
	// 전위 순회
    preOrder(0);
    cout << endl;
	// 중위 순회
    inOrder(0);
    cout << endl;
	// 후위 순회
    postOrder(0);
    cout << endl;
}


void preOrder(int NodeIdx)
{
    if (0 <= NodeIdx && NodeIdx <= 'Z' - 'A')
    {
        cout << static_cast<char>(NodeIdx + 'A');
        preOrder(graph[NodeIdx].first);
        preOrder(graph[NodeIdx].second);
    }
}
void inOrder(int NodeIdx)
{
    if (0 <= NodeIdx && NodeIdx <= 'Z' - 'A')
    {
        inOrder(graph[NodeIdx].first);
        cout << static_cast<char>(NodeIdx + 'A');
        inOrder(graph[NodeIdx].second);
    }
}


void postOrder(int NodeIdx)
{
    if (0 <= NodeIdx && NodeIdx <= 'Z' - 'A')
    {
        postOrder(graph[NodeIdx].first);
        postOrder(graph[NodeIdx].second);
        cout << static_cast<char>(NodeIdx + 'A');
    }
}