#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node {
private:
    Node* left;
    Node* right;
    Node* root;
public:
    T vaule;
    Node() : vaule('0'), left(nullptr), right(nullptr), root(nullptr) {};
    void SetLeft(Node* node) { this->left = node; }
    void SetRight(Node* node) { this->right = node; }
    Node* GetLeft() { return left; }
    Node* GetRight() { return right; }
    T GetValue() { return vaule; }
};
template <typename T> void Preorder(Node<T>* node) //전위 
{
    if (node == nullptr) return;
    cout << node->GetValue();
    Preorder(node->GetLeft());
    Preorder(node->GetRight());
}
template <typename T> 
void Inorder(Node<T>* node)//중위 
{
    if (node == nullptr) return; 
Inorder(node->GetLeft()); 
cout << node->GetValue();
Inorder(node->GetRight()); 
}
template <typename T> 
void Postorder(Node<T>* node) //후위 
{
    if (node == nullptr) return;
    Postorder(node->GetLeft());
    Postorder(node->GetRight());
    cout << node->GetValue();
}


int main() {
    int nodenumber;
    cin >> nodenumber;

    Node<char>* Treenode = new Node<char>[nodenumber];

    for (int i = 0; i < nodenumber; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;
        int nodename = a - 'A';
        Treenode[nodename].vaule = a;

         if (b != '.')
             Treenode[nodename].SetLeft(&Treenode[b-'A']);
         if (c != '.')
             Treenode[nodename].SetRight(&Treenode[c-'A']);

     }

    Preorder(&Treenode[0]);
    cout << endl;
    Inorder(&Treenode[0]);
    cout << endl;
    Postorder(&Treenode[0]);
    cout << endl;

    }

/*
### 1991 - 트리 순회

- 클래스 템플릿을 통해 트리의 한 노드를 구현
- 재귀함수를 통해 순위 방식에 따른 순회를 구현하였다.
- 배열을 이용 할 수 있지만, C++이니 클래스이용
*/