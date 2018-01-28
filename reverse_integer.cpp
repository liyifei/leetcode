#include <iostream>

using namespace std;

int reverse(int x) {

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
		//cout << carry << endl;
	}
	n = n * symbol;
	if( n > 2147483647 || n < -2147483648){
		n_int = 0;
	}else{
		n_int = n;
	}
	return n_int;
   
}

int main(){

	int x = 123;
	cout << reverse(x) << endl;
	x = -123;
	cout << reverse(x) << endl;
	x = 1534236469;
	cout << reverse(x) << endl;
	
	int a = 2147483649;
	cout << a << endl;
}
