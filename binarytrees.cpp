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

void printTree(struct node* node)
{
	if(node != NULL){
		printTree(node->left);
		cout<<node->data<<" ";		
		printTree(node->right);
	}
}

void printPostorder(struct node* node)
{
	if(node != NULL){
		printPostorder(node->left);
		printPostorder(node->right);
		cout<<node->data<<" ";
	}
}

bool hasPathSum(struct node* node, int sum){
	if( node != NULL){
		if(node->left == NULL && node->right == NULL){
			if(node->data == sum){
				return true;
			}
			return false;
		} else {
			if( (node->left != NULL && hasPathSum(node->left, sum-node->data)) || (node->right != NULL && hasPathSum(node->right, sum-node->data)) ){
				return true;
			} 
			return false;
		}
	}
	return false;
}

void printArray(int* path, int pathLen){
	for ( int i=0; i<pathLen; i++){
		cout<<path[i]<<" ";
	}
	cout<<endl;
}

void printPathsRecur(struct node* node, int* path, int pathLen)
{
	if(node==NULL) return;

	path[pathLen] = node->data;
	pathLen++;

	if(node->left==NULL && node->right==NULL){
		printArray(path, pathLen);
	} else {
		printPathsRecur(node->left, path, pathLen);
		printPathsRecur(node->right, path, pathLen);
	}
}

void printPaths(struct node* node)
{
	int path[1000];
	printPathsRecur( node, path, 0);
}

struct node* findLCA(struct node* node, int key1, int key2)
{
	if(node == NULL) return NULL;
	if(node->data == key1 || node->data == key2) return node;
	struct node* left_lcanode = findLCA(node->left, key1, key2);
	struct node* right_lcanode = findLCA(node->right, key1, key2);

	if(left_lcanode != NULL && right_lcanode != NULL) return node;
	if(left_lcanode != NULL) return left_lcanode;
	if(right_lcanode != NULL) return right_lcanode;
}

int main()
{
	struct node* root = buildOneTwoThree();
	insert(&root, 5); int x=0; int sum=0; bool v = false; int n1=0; int n2=0; struct node* temp;
	while(1){
		cout<<"1. Find Size\n2. Max Depth\n3. Min Value\n4. Inorder traversal\n5. Postorder traversal\n6. Has path sum?\n7. print all Root-to-Leaf paths\n8. Find Lowest Common Ancestor"<<endl;
		cin>>x;
		switch(x) {
		case 1:
			cout<<"size is: "<<size(root)<<endl;
			break;
		case 2:
			cout<<"maxdepth is: "<<maxDepth(root)<<endl;
			break;
		case 3:
			cout<<"minValue is: "<<minValue(root)<<endl;
			break;
		case 4:
			cout<<"inorder print: ";printTree(root);cout<<endl;
			break;
		case 5:
			cout<<"postorder print: ";printPostorder(root);cout<<endl;
			break;
		case 6:
			cout<<"enter path sum ";cin>>sum;
			 v = hasPathSum(root, sum);
			if(v){cout<<"Yes, has pathsum."<<endl;}else{cout<<"No, doesn't have path with that sum."<<endl;}
			break;
		case 7:
			printPaths(root);
			break;
		case 8:
			cout<<"enter key1"; cin>>n1;
			cout<<"\nenter key2"; cin>>n2;
			temp = findLCA(root, n1, n2);
			break;
		}
	}
	
	return 0;	
}










