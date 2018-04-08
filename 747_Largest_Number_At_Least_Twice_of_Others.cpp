#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dominantIndex(vector<int>& nums) {
	int nums_size = nums.size();
	if(nums_size < 2){
		return -1;
	}
	
	int Mx = INT_MIN;
	int Mx_index = -1; 
	int SecondMx =  INT_MIN;
	for(int i=0,len=nums_size;i<len;i++){
		if(nums[i] > SecondMx ){
			if(nums[i] > Mx){
				SecondMx = Mx;
				Mx = nums[i];
				Mx_index = i;
			}else{
				SecondMx = nums[i];
			}
		}
	}
	if(Mx >= SecondMx *2){
		return Mx_index;
	}else{
		return -1;
	}

}

int main(){
	
	vector<int> v = {3, 6, 1, 0};
	cout << dominantIndex(v) << endl;
	return 0;
}
