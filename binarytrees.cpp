#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int data)
{
	struct node* newNode = new node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bool lookup(struct node* node, int target) //lookup for a target and return boolean
{
	if(node == NULL){
		return false;
	} else {
		if(target == node->data){
			return true;
		} else {
			if(target < node->data){
				return lookup(node->left, target);	
			} else {
				return lookup(node->right, target);
			}
		}
	}
}

void insert(struct node** nodeRef, int data){
	if(*nodeRef == NULL){
		*nodeRef = createNode(data);
	} else {
		if(data <= (*nodeRef)->data){
			insert(&((*nodeRef)->left), data);
		} else {
			insert(&((*nodeRef)->right), data);
		}
	}
}

struct node* buildOneTwoThree()
{
	struct node* root = NULL;
	insert(&root, 2);
	insert(&root, 1);
	insert(&root, 3);

	return root;
}

int size(struct node* node)
{
	if(node == NULL){
		return 0;
	} else {
		return 1+size(node->left)+size(node->right);
	}
}

int maxDepth(struct node* node) //max depth of tree 
{
	if(node == NULL){
		return 0;
	} else {
		int leftdepth = maxDepth(node->left);
		int rightdepth = maxDepth(node->right);
		if( leftdepth >= rightdepth) {
			return 1+leftdepth;
		} else {
			return 1+rightdepth;
		}	
	}
}

int minValue(struct node* node) //minvalue in a BST
{
	if(node->left == NULL){
		return node->data;
	}
	return minValue(node->left);
}

int main()
{
	struct node* root = buildOneTwoThree();
	cout<<"size is: "<<size(root)<<endl;
	cout<<"maxdepth is: "<<maxDepth(root)<<endl;
	cout<<"minValue is: "<<minValue(root)<<endl;
}










