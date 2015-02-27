#include <iostream>
#include <string>
using namespace std;

void reverse(char* s)
{
	char* start = s;
	while(*start != '\0'){
		start++;
	}
	
	char* end = --start;
	start = s;
	while(start<end){
		char a = *start;
		*start = *end;
		*end = a;
		start++;
		end--;
	}
}



int main(){
	char s[500];
	cout<<"enter string:  ";
	cin>>s;
	reverse(s);
	cout<<"reversed string: "<<s<<endl;
	return 0;
}
