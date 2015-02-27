#include <iostream>

using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node* next;
	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
		next = NULL;
	}
}

class TreeOps{
public:
	void setInorderSuccessor(Node* root);
}

void TreeOps::setInorderSuccessor(Node* root)
{
	static Node* prev = NULL;
	if(root){
		setInorderSuccessor(root->left);
		if(prev){
			prev->next = root;
			
		}
		prev = root;
		setInorderSuccessor(root->right);
	}
}

int main()
{
	Node* root = new Node(20);
	root->left = new Node(8);
	root->right = new Node(22);
	root->left->left = new Node(4);
	root->left->right = new Node(12);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(14);
	
	return 0;
}
