#include <iostream>

using namespace std;

int lms2(int *sat, int n)
{
	int length[n]; int max_length = 1; int max_length_index; int prev_index[n];

	for(int i=0; i<n; i++){
		length[i] = 1;
		prev_index[i] = i;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(sat[j]<sat[i] /*&& gpa[j]>gpa[i] */&& (length[j]+1)>length[i]){
				length[i] = length[j]+1;
				prev_index[i] = j;
			}
		}
		if(max_length < length[i]){
			max_length_index = i; 
			max_length = length[i];	
		}
	}

	int lms[max_length]; int k = prev_index[max_length_index];
	cout<<k<<endl;
	lms[max_length-1] = sat[max_length_index];
	/*for(int i=0; i<n; i++){
		//length[i] = 1;
		cout<<prev_index[i]<<" ";
	}
	cout<<endl;*/
	for(int i=max_length-2; i>=0; i--){
		lms[i] = sat[k];
		cout<<lms[i]<<" ";
		k = prev_index[k];
	}
	//cout<<endl;
	return max_length;
}

int lms(int *sat, int *gpa, int n)
{
	int length[n];

	for(int i=0; i<n; i++){
		length[i] = 1;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			if(sat[j]<sat[i] /*&& gpa[j]>gpa[i] */&& (length[j]+1)>length[i]){
				length[i] = length[j]+1;
			}
		}
	}

	return length[n-1];
}

int main(){
	int n = 0;
	cout<<"enter no of students"<<endl;
	cin>>n;
	cout<<"enter students' sat scores: "<<endl;
	int sat[n]; int gpa[n];
	for(int i=0; i<n; i++){
		cin>>sat[i];
	}
/*
	cout<<"enter students gpas: "<<endl;
	for(int i=0; i<n; i++){
		cin>>gpa[i];
	}
*/
	int length = lms2(sat, n);

//	int length = lms(sat, gpa, n);
	cout<<length<<endl;

	return 0;
}
