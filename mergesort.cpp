#include <iostream>

using namespace std;

void merge(int *A, int p, int q, int r)
{
	int larr = 0;	int rarr = 0;
	int n1 = q-p+1;	int n2 = r-q;
	int left[n1];	int right[n2];

	for(int i=0; i<n1; i++){
		left[i] = A[p+i];
	}

	for(int i=0; i<n2; i++){
		right[i] = A[q+i+1];
	}

	int k=p;

	while(larr<n1 && rarr<n2){
		if(left[larr] <= right[rarr]){
			A[k] = left[larr++];
			k++;
		} else {
			A[k] = right[rarr++];
			k++;	
		}
	}

	while(larr<n1){
		A[k++] = left[larr++];
	}

	while(rarr<n2){
		A[k++] = right[rarr++];
	}
}

void mergeSort(int *A, int p, int r)
{
	int q=0;
	if(p<r){
		q = (p + r)/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}

int main()
{	
	int n;
	cout<<"enter no of elements"<<endl;
	cin>>n;
	int A[n];
	cout<<"enter elements"<<endl;
	for(int i=0; i<n; i++){
		cin>>A[i];
	}

	mergeSort(A, 0, n-1);

	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
}
