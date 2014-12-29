#include <iostream>

using namespace std;

int partition(int *A, int p, int r)
{
	int x = A[r];
	int i = p-1;	int temp = 0;

	for(int j = p; j < r; j++ ){
		if( A[j] <= x){
			i++;
			temp = A[i];	A[i] = A[j];	A[j] = temp;			
		}
	}

	temp = A[i+1];	A[i+1] = A[r];	A[r] = temp;
	return i+1;
}

void quickSort(int *A, int p, int r)
{
	int q = 0;
	if(p < r){
		q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
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

	quickSort(A, 0, n-1);

	for(int i=0; i<n; i++){
		cout<<A[i]<<" ";
	}
}
