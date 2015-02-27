#include <iostream>
#include <cstdlib>

using namespace std;

class Heap{
private:
	int totalElements;
	int currentElements;
	int* h;
public:
	void insert(int data);
	void remove(int i);
	Heap(int n){
		totalElements = n;
		currentElements = 0;
		h = (int*)malloc(n*sizeof(int));
	}
	void heapifyDown(int i);
	void heapifyUp(int i);
	void swap(int i, int j);

};

void Heap::heapifyUp(int i)
{
	int temp =0;
	if(i>0){
		int j = (i-1)/2;
		if(h[i]<h[j]){
			temp = h[i];
			h[i] = h[j];
			h[j] = temp;
			heapifyUp(j);
		}
	}
}

void Heap::swap(int i, int j)
{
	int temp = h[i];
	h[j] = h[i];
	h[i] = temp;
}

void Heap::heapifyDown(int i)
{
	int temp = 0;
	int j = 0;
	if((2*i+1)<(currentElements-1)){
		int left = 2*i+1;
		int right = 2*i+2;
		if(h[left]<h[right]){
			j = left;
		} else {
			j = right;
		}
	} else if((2*i+1)==(currentElements-1)){
		j = 2*i+1;
	}
	swap(i,j);
}

void Heap::remove(int i)
{
	int temp = h[currentElements-1];
	h[currentElements-1] = h[i];
	h[i] = temp;
	int j=(i-1)/2;
	if(h[i]<h[j]){
		heapifyUp(i);
	} else {
		heapifyDown(i);
	}	
}

void Heap::insert(int data)
{
	h[currentElements] = data;
	heapifyUp(currentElements);	
}

int main()
{
	int b[100];
	int a[] = {5, 1, 3, 4, 2, 8};
	//insertionsort(a,6);
	for(int i=0; i<6; i++){
		cout<<a[i]<<" ";
	}
}
