#include <iostream>
#include <vector>
using namespace std;

string reverseWords(string s) {
	int begin = 0;
	for(int i=0,len=s.length();i<=len;i++){
		if(i == len || s[i] == ' '){
			reverse(&s[begin],&s[i]);
			begin = i+1;
		}
	} 
	return s;
}

int main(){

	string s =  "Let's take LeetCode contest";
	cout << reverseWords(s) << endl;
	return 0;
}
