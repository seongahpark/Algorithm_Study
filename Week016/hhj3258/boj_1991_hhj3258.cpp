#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char left;
    char right;
};

// 전위 순회
void preorder(const map<char, Node> &tree, char node)
{
    if (node == '.')
        return;
    else
    {
        cout << node;
        preorder(tree, tree.at(node).left);
        preorder(tree, tree.at(node).right);
    }
}

// 중위 순회
void inorder(const map<char, Node> &tree, char node)
{
    if (node == '.')
        return;
    else
    {
        inorder(tree, tree.at(node).left);
        cout << node;
        inorder(tree, tree.at(node).right);
    }
}

// 후위 순회
void postorder(const map<char, Node> &tree, char node)
{
    if (node == '.')
        return;
    else
    {
        postorder(tree, tree.at(node).left);
        postorder(tree, tree.at(node).right);
        cout << node;
    }
}

int main()
{
    int N;
    cin >> N;

    char parent, left, right;
    map<char, Node> tree;
    for (int i = 0; i < N; i++)
    {
        cin >> parent >> left >> right;

        tree[parent].left = left;
        tree[parent].right = right;
    }

    preorder(tree, 'A');
    cout << '\n';

    inorder(tree, 'A');
    cout << '\n';

    postorder(tree, 'A');
    cout << '\n';
}