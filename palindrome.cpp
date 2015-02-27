#include <iostream>

using namespace std;

bool palindrome(char* s)
{
	char* start = s;
	char* end = s;
	while(*end != '\0') {
		end++;
	}
	end--;
	char temp;
	/*while(start<end) {
		temp = *start;
		*start = *end;
		*end = temp;
		start++; end--;
	}*/

	while(start<end) {
		if(*start != *end){
			return false;
		}
		start++; end--;
	}

	return true;
}

int main()
{
	char s[100];
	cout<<"enter string:"<<endl;
	cin>>s;
	cout<<palindrome(s)<<endl;
	return 0;
}
