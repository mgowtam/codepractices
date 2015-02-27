#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

void lot(struct node* head)
{
	
}

void insert(struct node** headRef, int data)
{
	struct node* newNode = new node;
	newNode->data = data; newNode->left = NULL; newNode->right = NULL;

	if(*headRef == NULL){
		*headRef = newNode;
	} else {
		struct node* current = *headRef;
		while(1){
			if(data > current->data){
				if(current->right != NULL){
					current = current->right;
				} else {
					current->right = newNode;
					break;
				}
			} else {
				if(current->left != NULL) {
					current = current->left;
				} else {
					current->left = newNode;
					break;
				}
			}
		}
	}
}

int main(){
	int i=0;
	int option=0; int element=0;
	struct node* head = NULL;
	
	while(1) {
		cout<<"select an option:\n1. Insert an element into binary tree\n2. Do Level Order Traversal"<<endl;
		cin>>option;
		switch(option){
			case 1:
				insert();
				break;
			case 2:
				cout<<"enter element to insert"<<endl;
				cin>>element;
				lot(&head, element);
				break;
		}	
	}
}
