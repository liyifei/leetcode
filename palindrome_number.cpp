#include <iostream>

using namespace std;

bool isPalindrome(int number) {
  
	int x = number;
	long n = 0;
	int n_int = 0;
	int symbol = 1;
	if(x < 0){
		symbol = -1;
		x = x * -1;
	}
	int carry = 0;
	while( x > 0){
		carry = x % 10;
		n = n * 10 + carry; 
		x = x / 10;
	}
	//n = n * symbol;
	
	cout << number << "," << n << endl;
	return number==n;
	//if( n > 2147483647 || n < -2147483648){
	//	n_int = 0;
	//}else{
	//	n_int = n;
	//}
}

int main(){

	int x = -2147447412;
	cout << isPalindrome(x) << endl;

	//int a = 2147483649;
	//cout << isPalindrome(a) << endl;
}
