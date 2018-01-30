#include <iostream>
using namespace std;

bool judgeCircle(string moves) {

	int vertical = 0;
	int horizontal = 0;
	int arr[256] = {0};
	arr[ int('U') ] = -1; 	
	arr[ int('D') ] = -1; 	
	arr[ int('L') ] = 1; 	
	arr[ int('R') ] = 1; 	

	for(int i=0,len=moves.length();i<len;i++){
		if( arr[ int(moves[i]) ] != 0 ){
				if(  arr[ int(moves[i]) ] > 0 ){
					if(moves[i] == 'L'){
						horizontal++;
					}else{
						horizontal--;
					}
				}else{
					if(moves[i] == 'U'){
						vertical++;
					}else{
						vertical--;
					}
				}

		}
	}   
	if( vertical ==0 && horizontal ==0 ){
		return true;
	}
	return false;

}


int main(){

	judgeCircle("LR") ;
	return 0;
}
