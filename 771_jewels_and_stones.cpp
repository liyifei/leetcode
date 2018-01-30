#include <iostream>
using namespace std;

int numJewelsInStones(string J, string S) {

	bool J_arr[256] = {false} ;
	for(int i=0,len=J.length();i<len;i++){
		J_arr[ (int)J[i] ] = true;
	}	
	int result = 0;
	for(int i=0,len=S.length();i<len;i++){
		if( J_arr[ (int)S[i]]  ){
			result ++;
		}
	}	
 
	return result;  
}

int main(){

	cout << numJewelsInStones("aK","aKKKA") << endl;
	return 0;
}
