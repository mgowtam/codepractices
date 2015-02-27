#include<iostream>

using namespace std;

void bubblesort(int* a,int length)
{
	int temp =0;
	for(int i=0;i<length/2; i++) {
		for(int j=0;j<length-1; j++) {
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void selectionsort(int* a,int length)
{
	int temp = 0; int min=0;
	for(int i=0;i<length; i++) {
		min=i;
		for(int j=i+1;j<length; j++) {
			if(a[min]>a[j]){
				min = j;			
			}
		}
			temp = a[min];
				a[min] = a[i];
				a[i] = temp;
			
	}
	
}

void insertionsort(int* a, int length)
{
	int temp = 0; int min=0;
	for(int i=0;i<length; i++) {
		min=i;
		for(int j=i;j>0; j--) {
			if(a[j]<a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;			
			}
		}
				
	}

}

int main()
{
	int a[] = {5, 1, 3, 4, 2, 8};
	insertionsort(a,6);
	for(int i=0; i<6; i++){
		cout<<a[i]<<" ";
	}
}
