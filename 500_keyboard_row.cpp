#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<string> findWords(vector<string>& words) {

	unordered_set<char> dict1 = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
	unordered_set<char> dict2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'};
	unordered_set<char> dict3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'}; 

	vector<string> res;
	
	for(auto &word:words){
		bool d1 = true,d2 = true,d3 = true;

		for(auto &w:word){
			if(d1){
				auto it = dict1.find(w);
				if(it == dict1.end()){
					d1 = false;
				}
			}
			if(d2){
				auto it = dict2.find(w);
				if(it == dict2.end()){
					d2 = false;
				}
			}
			if(d3){
				auto it = dict3.find(w);
				if(it == dict3.end()){
					d3 = false;
				}
			}
		}	

		if(d1 || d2 || d3){
			res.push_back(word);
		}
	}
	

	return res;   
}


int main(){

	vector<string> v = {"Hello", "Alaska", "Dad", "Peace"};
	vector<string> r = findWords(v);
	for(auto &i : r){
		cout << i << endl;
	}

	return 0;
}
