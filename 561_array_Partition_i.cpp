#include <iostream>
#include <vector>
using namespace std;

int arrayPairSum(vector<int>& nums) {

	sort(nums.begin(),nums.end());   
	int result = 0;
	for(int i=0,len=nums.size();i<len;i+=2){
		result += nums[i] ;
	}
	return result;
}

int main(){

	vector<int> a ;
	a.push_back(1);
	a.push_back(4);
	a.push_back(3);
	a.push_back(2);
	cout << arrayPairSum(a) << endl;

	return 0;
}
