#include <iostream>
#include <vector>
using namespace std;

bool IsSelfDividingNumbers(int n){
	
	int tmp = n;
	while(tmp > 0){
		int carry = tmp % 10;
		if(carry == 0 || n % carry != 0){
			return false;
		}
		tmp  = tmp / 10;
	}
	return true;

}

vector<int> selfDividingNumbers(int left, int right) {
   
	vector<int> result ;
	for(int i=left;i<=right;i++){
		if(IsSelfDividingNumbers(i)){
			//cout << i << endl;
			result.push_back(i);
		}	
	}
	return result;
}


int main(){
	
	int left = 1;
	int right = 22;
	selfDividingNumbers(1,22);
	return 0;
}
