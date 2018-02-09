#include <iostream>
using namespace std;

int findComplement(int num) {
	
	unsigned int mask = ~0;   
 	while( mask & num ){
		mask <<= 1;
	}
	return ~mask & ~num ;
}


int main(){

	int a = 5;
	cout << findComplement(5) << endl;
	return 0;
}
