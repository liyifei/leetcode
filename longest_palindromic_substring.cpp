#include <iostream>

using namespace std;

string longestPalindrome(string s) {
	int size = s.size();
	int a_len = 2 * size +1;
	char *a = new char[ a_len ];
	for(int i=0;i<size;i++){
		a[2*i] = '#';
		a[2*i+1] = s[i];
	}
	a[a_len-1] = '#';

	int *RL = new int[a_len];
	int pos = 0;
	int MaxRight = 0;
	int MaxLen = 0;
	int MaxPos = 0;
	for(int i=0;i<a_len;i++){
		if(i < MaxRight){
			RL[i] = min( RL[2*pos-i],MaxRight-i  );
		}else{
			RL[i] = 1;
		}
		
		while( i-RL[i] >=0 && i+RL[i] < a_len && a[ i-RL[i] ] == a[i+RL[i]]  ){
			RL[i] ++ ;
		}
		
		if( RL[i] + i > MaxRight  ){
			MaxRight = RL[i] + i -1;
			pos = i;
		}		
		
		if( RL[i] > MaxLen){
			MaxPos = pos;
			MaxLen = RL[i];
		}
		

	}

	return s.substr((MaxPos - MaxLen + 1) / 2, MaxLen - 1);

}

int main(){

	// string a = "cbbd";
	string a = "babad";
	cout << longestPalindrome(a) << endl;
	return 0;
}
