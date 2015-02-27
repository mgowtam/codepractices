#include <iostream>
#include <climits>

using namespace std;

struct node{
	struct node* left;
	struct node* right;
	int data;
};

struct node* newnode(int x)
{
	node* tempnode = new node;
	tempnode->left = NULL;
	tempnode->right = NULL;
	tempnode->data = x;
	return tempnode;
}



bool isBst1(struct node* root, int min, int max)
{
	if(root == NULL){
		return true;
	}

	if(root->data < min || root->data>max){
		return false;
	}

	return (isBst1(root->left,min,root->data) && isBst1(root->right, root->data+1, max));
}

bool isBst2(struct node* root)
{
	static struct node* prev = NULL;
	if(root) {
		if(!isBst2(root->left)) {
			return false;	
		}

		if(prev!=NULL && prev->data>root->data){
			return false;	
		}

		prev = root;
		return isBst2(root->right);
	}	

	return true;
}

bool isBstUtil(struct node* root)
{
	return isBst1(root, INT_MIN,INT_MAX);
}

int main()
{
	struct node* root = new node;
	root	->data = 5;
	root->left = newnode(3);
	root->left->right = newnode(4);
	root->right = newnode(6);

	cout<<isBst2(root)<<endl;
	return 0;
}
