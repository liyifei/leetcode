#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
    unordered_map<int,int> hash_b ;
    for(int i=0,len=B.size();i<len;i++ ){
        hash_b[ B[i] ] = i;
    }
    vector<int> result;
    for(vector<int>::iterator iter=A.begin();iter!=A.end();iter++){
        result.push_back( hash_b.at(*iter) );
    }
    return result;
}


int main(){

	vector<int> A;
    vector<int> B;
    A.push_back(12);
    A.push_back(28);
    A.push_back(46);
    A.push_back(32);
    A.push_back(50);
    B.push_back(50);
    B.push_back(12);
    B.push_back(32);
    B.push_back(46);
    B.push_back(28);

    vector<int> C;
    C = anagramMappings(A,B);

    for(vector<int>::iterator iter=C.begin();iter!=C.end();iter++){
        cout << (*iter) << endl;
    }

}
