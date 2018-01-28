#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int arr_size = nums.size();
    vector<int> result;
    for(int i=0;i<arr_size-1;i++){
        for(int j=i+1;j<arr_size;j++){
            if(nums[i] + nums[j] == target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
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
