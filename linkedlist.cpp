#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* next;
};

int length(struct node* head)
{
	struct node* temp = NULL;
	temp = head; int count = 0;
	while( temp != NULL ){
		count++;
		temp = temp->next;
	}	
	return count;
}

void push(struct node** headRef, int data) //Inserting at head
{
	struct node* newnode = new node;
	newnode->data = data;
	newnode->next = *headRef;
	*headRef = newnode;
}

struct node* buildOneTwoThree()
{
	struct node* head = new node;
	head->data = 3;
	head->next = NULL;
	push(&head, 2);
	push(&head, 1);

	return head;
}

void printList(struct node* head)
{
	struct node* temp = head;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;	
	}
	cout<<endl;
}

void basicsCaller()
{
	struct node* head;
	int len;
	head = buildOneTwoThree(); // Start with {1, 2, 3}
	push(&head, 13); // Push 13 on the front, yielding {13, 1, 2, 3}
			// (The '&' is because head is passed
			// as a reference pointer.)
	push(&(head->next), 42); //
	len = length(head); // Computes that the length is 5.
	printList(head);
	cout<<len<<endl;
}

int count(struct node* head, int val) //get count of a number in list
{
	int count = 0;
	struct node* temp = head;
	while(temp!=NULL){
		if(temp->data == val){
			count++;
		}
		temp = temp->next;
	}	
	return count;
}

void countTest() // test for get count of a number in list
{
	struct node* head = buildOneTwoThree();
	push(&head, 2);
	int counter = count(head, 2);
	cout<<"count of 2 is: "<<counter<<endl;
}

int getNth(struct node* head, int index) //get value at index
{
	struct node* temp = head;
	int i=0;
	while(i!=index){
		if(temp->next!=NULL){
			temp = temp->next;
			i++;
		} else {
			break;
		}		
	}

	return temp->data;
}

void getNthTest() //test for get value at index
{
	struct node* head = buildOneTwoThree();
	int lastNode = getNth(head, 2);
	cout<<"data at index 2 is: "<<lastNode<<endl;
}

void deleteList(struct node** headref) // delete list
{
	struct node* temp = *headref;
	struct node* next = NULL;
	while(temp!=NULL){
		next = temp->next;
		delete temp;
		temp = next;
	}
	
	*headref = NULL;
}

void deleteListTest() //test for delete list
{
	struct node* head = buildOneTwoThree();
	deleteList(&head);
	if(head == NULL){
		cout<<"list deleted"<<endl;	
	}
}

int pop(struct node** headref) //pop element
{
	int data = 0;
	if(*headref == NULL){
		data = -1;
	} else {
		struct node* temp = (*headref)->next;
		data = (*headref)->data;
		delete *headref;
		*headref = temp;
	}
	return data;
}

void popTest() //test for pop element
{
	struct node* head = buildOneTwoThree();
	int a = pop(&head);
	//cout<<"length: "<<length(head)<<endl;
	int b = pop(&head);
	//cout<<"length: "<<length(head)<<endl;
	int c = pop(&head);
	//cout<<"length: "<<length(head)<<endl;
	int len = length(head);
	cout<<"popped a,b,c and length: "<<a<<" "<<b<<" "<<c<<" "<<len<<endl;
}

void insertNth(struct node** headref, int index, int data) //insert at a specific index
{
	struct node* prev = NULL;
	struct node* temp = *headref;
	int i=0;	
	while(i!=index){	
		prev = temp;
		temp = temp->next;
		i++;
	}

	struct node* newnode = new node;
	newnode->data = data;
	if(prev == NULL){
		newnode->next = *headref;
		*headref = newnode;
	} else {
		newnode->next = prev->next;
		prev->next = newnode;
	}
	
	
}

void insertNthTest()
{
	struct node* head = NULL;
	insertNth(&head, 0, 13);
	printList(head);
	insertNth(&head, 1, 42);
	printList(head);
	insertNth(&head, 1, 5);
	printList(head);

	deleteList(&head);	
	printList(head);
}

void sortedInsert(struct node** headref, struct node* newnode) //insert the new node in its increasing order position
{
	struct node* prev = NULL;
	struct node* next = NULL;
	struct node* current = *headref;

	if(*headref == NULL){
		//prev->next = newnode;
		newnode->next = current;
		*headref = newnode;
	}

	while(current != NULL){
		if(current->data >= newnode->data){
			if(prev == NULL){
				newnode->next = current;
				*headref = newnode;
			} else {
				prev->next = newnode;
				newnode->next = current;
			}
			break;
		} else {
			prev = current;
			current = current->next;
		}
	}
	if(current == NULL){
		prev->next = newnode;
		newnode->next = current;
	}	
}

void sortedInsertTest()
{
	struct node* head = new node;
	head->data = 3;
	head->next = NULL;

	struct node* head1 = new node;
	head1->data = 5;
	head1->next = NULL;

	struct node* head2 = new node;
	head2->data = 1;
	head2->next = NULL;

	sortedInsert(&head, head1); sortedInsert(&head, head2);
	//push(&head, 1);

	printList(head);
	//return head;
}

void insertSort(struct node** headref){
}

void append(struct node** aref, struct node** bref) //append listB to the end of listA.
{
	if(*aref == NULL){
		*aref = *bref;
		*bref = NULL;
	} else {
		struct node* temp = *aref;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = *bref;
		*bref = NULL;
	}
}

void appendTest(){
	struct node* a = buildOneTwoThree();
	struct node* b = buildOneTwoThree();

	append(&a, &b);
	printList(a);
}

void frontBackSplit(struct node* source, struct node** frontRef, struct node** backRef) //splits list into front half and back half
{
	struct node* fast = source;
	struct node* slow = source;
	*frontRef = source;

	while(fast->next != NULL){
		if( (fast->next)->next != NULL ){
			fast = (fast->next)->next;
			slow = slow->next;
		} else {
			*backRef = slow->next;
			slow->next = NULL;
			break;
		}
	}
	
	if(fast->next == NULL){
		*backRef = slow->next;
		slow->next = NULL;
	}
}

void frontBackSplitTest()
{
	struct node* a = buildOneTwoThree();
	struct node* b = buildOneTwoThree();
	push(&a, 5);
	append(&a, &b);
	cout<<"after appending"<<endl;
	printList(a);

	cout<<"after splitting"<<endl;
	struct node* front = NULL; struct node* back = NULL;
	frontBackSplit(a, &front, &back);
	printList(front); cout<<"second"<<endl; 	printList(back);
}

void removeDuplicates(struct node* head) //remove duplicates from a increasing order sorted list
{
	struct node* prev = head;
	struct node* current = head->next;

	while(current != NULL){
		if(current->data == prev->data){
			prev->next = current->next;
			delete(current);
			current = prev->next;
		} else {
			prev = current;
			current = current->next;
		}
	}
}

void removeDuplicatesTest()
{
	struct node* a = buildOneTwoThree();
	push(&a, 1);
	printList(a);
	removeDuplicates(a);
	printList(a);
}

void moveNode(struct node** destRef, struct node** sourceRef) //move node from front of source to fornt of destination
{
	struct node* temp = *destRef;
	*destRef = *sourceRef;
	*sourceRef = (*sourceRef)->next;
	(*destRef)->next = temp;
}

void moveNodeTest()
{
	struct node* a = buildOneTwoThree();
	struct node* b = buildOneTwoThree();
	moveNode(&a, &b);
	printList(a);
	cout<<"second"<<endl;
	printList(b);
}

void alternatingSplit(struct node* source, struct node** aRef, struct node** bRef) //split into 2 sublists with alternate elements going into each list
{
	struct node* temp = source;
	while(source!=NULL){
		moveNode(aRef, &source);
		//printList(source);cout<<endl;
		if(source!=NULL){
			moveNode(bRef, &source);	
		}
	}
}

void alternatingSplitTest()
{
	struct node* head = buildOneTwoThree();
	struct node* a = NULL; struct node* b = NULL;
	printList(head);cout<<endl;
	alternatingSplit(head, &a, &b);
	printList(a);cout<<"second"<<endl; printList(b);
}

struct node* shuffleMerge(struct node* a, struct node* b) //merge two lists taking elements alternately from each list
{
	struct node* mergedHead = NULL; struct node* temp = NULL;
	struct node* aCurrent = a; struct node* bCurrent = b;
	while(a != NULL && b != NULL){
		moveNode(&temp, &a);
		append(&mergedHead, &temp);
		moveNode(&temp, &b);
		append(&mergedHead, &temp);
	}
	if(a != NULL){
		append(&mergedHead, &a);
	}
	if(b != NULL){
		append(&mergedHead, &b);
	}
	return mergedHead;
}

void shuffleMergeTest()
{
	struct node* a = buildOneTwoThree();
	struct node* b = buildOneTwoThree();
	push(&b,5);
	push(&b,6);
	push(&b,8);	
	struct node* head = shuffleMerge(a,b);
	printList(head);
}

int main()
{
	//basicsCaller();
	//countTest();	
	//getNthTest();
	//deleteListTest();
	//popTest();
	//insertNthTest();
	//sortedInsertTest();	
	//appendTest();
	//frontBackSplitTest();
	//removeDuplicatesTest();
	//moveNodeTest();
	//alternatingSplitTest();
	shuffleMergeTest();
	return 0;
}





