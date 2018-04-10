#include <iostream>
#include <vector>
using namespace std;

string boldWords(const vector<string>& words, string s) {  
	int s_len = s.size();
	vector<int> bold_index(s_len,false);
	for(vector<string>::const_iterator iter=words.begin();iter!=words.end();iter++){
		int pos = s.find(*iter,0);
		while(pos!=string::npos){
			int word_len = (*iter).size();
			while(word_len--){
				bold_index[pos+word_len] = true;
			}
			pos = s.find(*iter,pos+1);
		}
	}
  int now = 0;  
  string tmp = "";  
  for (int i = 0; i < s.size(); i++)  
  {  
      if (bold_index[i] == true)  
      {  
          if (now == 0) {   
              tmp.insert(tmp.size(), "<b>"); now = 1;   
          }  
            
      }  
      else  
      {  
          if (now == 1) {  
              tmp.insert(tmp.size(), "</b>"); now = 0;  
          }  
      }  
      tmp.push_back(s[i]);  
  }  
  if (now == 1)  
  {  
      tmp.insert(tmp.size(), "</b>");  
  }  
	return tmp;
}  

int main(){

	string str = "aabcd";
	vector<string>words = {"ab","bc"}; 
	string str_bold = boldWords(words,str);
	cout << str_bold << endl;
	return 0;
}
