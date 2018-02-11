#include <iostream>
#include <algorithm>
using namespace std;

string reverseString(string s) {
	
	int i=0,j = s.length()-1;
	while(i<j){
		swap(s[i++],s[j--] );
	}
	return s;

}


int main(){

	string a = "hello";
	cout << reverseString(a) << endl;	

	return 0;
}
