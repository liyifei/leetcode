#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
  int a=0,b=0,t=0;
	for(int nums:cost){
		t = min(a,b) + nums;
		a = b;
		b = t;
	}
	return min(a,b);  
}

int main(){
	
	vector<int> test = {10, 15, 20};
	cout << minCostClimbingStairs(test);
	
	return 0;
}
