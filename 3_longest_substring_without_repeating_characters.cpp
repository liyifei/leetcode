#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
 
	int size = s.size();
	int max_length = 0;
	int tmp_max_length = 0;
	int max_length_begin = 0;
	int tmp_max_length_begin = 0;
	unordered_map<char,int> char_hash;
	for(int i=0;i<size;i++){
		if(char_hash.find(s[i]) == char_hash.end() || char_hash[ s[i] ] < tmp_max_length_begin  ){
			tmp_max_length++;			
			//cout << "current char is " << s[i] << " not match" << endl;
		}else{
			//cout << "current char is " << s[i] << "  match" << endl;
			if(tmp_max_length > max_length){
				max_length = tmp_max_length;
				max_length_begin = tmp_max_length_begin;
			}
			tmp_max_length = i - char_hash[ s[i] ] ;
			tmp_max_length_begin = char_hash[ s[i] ]+1;
		}
		char_hash[s[i]] = i;
	}
  if(tmp_max_length > max_length){
    max_length = tmp_max_length;
    max_length_begin = tmp_max_length_begin;
  }   
	return max_length;
	//return s.substr(max_length_begin,max_length);
   
}


int main(){

	string a = "c";
	cout << lengthOfLongestSubstring(a) << endl;

}
