#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	Node* leftNode, *rightNode;
	int value;
};

class BST {
public:
	BST() :RootNode(nullptr) {};

	void AddNode(int value);
	void Inorder(Node* start);
	void Postorder(Node* start);
	Node* RootNode;
};

//중위 순회 알고리즘
void BST::Inorder(Node* start) {
	if (start != nullptr) {
		Inorder(start->leftNode);
		cout << start->value << "\n";
		Inorder(start->rightNode);
	}
}
//후위 순회 알고리즘
void BST::Postorder(Node* start) {
	if (start != nullptr) {
		Postorder(start->leftNode);
		Postorder(start->rightNode);
		cout << start->value << "\n";
	}
}

void BST::AddNode(int value) {
	//추가할 노드 하나
	Node* node = new Node();
	//루트노드를 저장할 노드
	Node* tmpRootNode = nullptr;
	//새로운 노드의 값 지정
	node->value = value;
	//만약 이번이 처음 노드라면 현재 노드가 루트
	if (RootNode == nullptr) RootNode = node;
	else {//아니라면 탐색을 통해 루트 노드 설정
		Node* ptr = RootNode;
		while (ptr !=nullptr){
			tmpRootNode = ptr;
			if (node->value < ptr->value)
				ptr = ptr->leftNode;
			else
				ptr = ptr->rightNode;
		}

		//마지막으로 한번 더 자리설정
		if (node->value < tmpRootNode->value)
			tmpRootNode->leftNode = node;
		else
			tmpRootNode->rightNode = node;
	}
}

int main() {
	BST* MyBSTREE = new BST();

	int num;
	while (cin >> num)
	{
		if (num == EOF)break;
		MyBSTREE->AddNode(num);
	}

	MyBSTREE->Postorder(MyBSTREE->RootNode);
}

/*
### 5639 - 이진 탐색 트리

- 이진 탐색 트리를 구현해서 해결
- While(cin>>val) 을 사용
*/