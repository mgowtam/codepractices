#include <iostream>
#include <stack>

using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

void preorder(Node* root)
{
	stack<Node*> myStack;
	myStack.push(root);

	while(!myStack.empty()){
		Node* current = myStack.top();
		cout<<current->data<<" ";
		myStack.pop();
		if(current->right)
			myStack.push(current->right);
		if(current->left)
			myStack.push(current->left);
	}
}

void inorder(Node* root)
{
	stack<Node*> myStack;
	//myStack.push(root);
	Node* current = root;
	int done = 0;
	int count=0;

	while(!done) {
		if(current!=NULL){
			myStack.push(current);
	//		cout<<"size: "<<myStack.size()<<endl;
			current = current->left;
		} else {
			if(!myStack.empty()){
				current = myStack.top();
				myStack.pop();
				count++;
				cout<<current->data<<" "<<count<<" "<<myStack.size()<<endl; 
				current = current->right;				
				//myStack.push(current->right);
			} else {
				//cout<<myStack.size()<<endl;
				done =1;
			}
			
		}		
	}
}

void postorder(Node* root)
{
	stack<Node*> myStack;
	Node* current = root;
	//cout<<current->data;
	do{
		if(current!=NULL){
			if(current->right){
				myStack.push(current->right);
			}
			myStack.push(current);
			current = current->left;
		} else {
			current = myStack.top();
			myStack.pop();
			
			if( !myStack.empty() && current->right == myStack.top()){
				myStack.pop();
				myStack.push(current);
				current = current->right;			
			} else {
				cout<<current->data<<" ";
				current = NULL;
			}
			
			
		}
	} while(!myStack.empty());
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	//root->left->left = new Node(4);
	//root->left->right = new Node(5);
	root->right = new Node(3);
	//root->right->left = new Node(6);
	//root->right->right = new Node(7);

	postorder(root);
	return 0;
}
