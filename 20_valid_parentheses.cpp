#include <iostream>
#include <stack>
using namespace std;

bool isLeft(char a){
	return ( a == '(' || a == '{' || a == '[' );
}
bool isClose(char a,char b){
 if(a == '(') return (b == ')');
 if(a == '{') return (b == '}');
 if(a == '[') return (b == ']');
}

bool isValid(string s) {

	unsigned int s_len = s.length(); 
	if(s_len % 2 != 0){
		return false;
	}
	stack<char> stk;

	for(unsigned int i=0;i<s_len;i++){
		if( isLeft(s[i])  ){
			stk.push(s[i]);
		}else{
			if(stk.empty() || !isClose( stk.top(),s[i]  ) ){
				return false;
			}
			stk.pop();
		}
		
	}
	return stk.empty();
	
 
}

int main(){
	
	cout << isValid("([(])") << endl;
	return 0;
}
