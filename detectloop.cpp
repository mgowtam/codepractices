#include <iostream>

using namespace std;

class Node{
	public:
	Node* next;
	int data;
	Node(int x){
		data = x;
		next = NULL;	
	}
};

class List{
public:
	Node* detectloop(Node* root);	
	Node* findMiddle(Node* root);	
};

Node* List::detectloop(Node* root)
{
	Node* slow_ptr = root;
	Node* fast_ptr = root;

	do {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	} while(slow_ptr != fast_ptr);

	slow_ptr = root;
	while(slow_ptr != fast_ptr) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
	}

	return slow_ptr;
}

Node* List::findMiddle(Node* root)
{
	Node* slow_ptr = root;
	Node* fast_ptr = root;

	while(fast_ptr != NULL && fast_ptr->next != NULL) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;
		if(fast_ptr!=NULL)
			fast_ptr = fast_ptr->next;
	}

	return slow_ptr;
}

int main()
{
	Node* head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);

	List* l = new List();
	//Node* n = l->detectloop(head);
	//cout<<n->data<<endl;
	Node *n = l->findMiddle(head);
	cout<<n->data<<endl;
}


