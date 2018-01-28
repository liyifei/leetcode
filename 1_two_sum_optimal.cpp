#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int arr_size = nums.size();
    //vector<int> result;
		unordered_map<int,int> hash;
    for(int i=0;i<arr_size;i++){
			int number_to_find = target - nums[i];			
			if( hash.find(number_to_find) !=hash.end() ){
				vector<int> result = {hash[number_to_find],i};
				return result;
			}
			hash[ nums[i] ] = i;
    }
}

int main(){

	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	int target = 4;
	
	vector<int> result = twoSum(a,target);
	cout << result[0] << "," << result[1] << endl;

	return 0;
}
