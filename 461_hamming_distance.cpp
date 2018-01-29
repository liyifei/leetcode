#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int hammingDistance(int x, int y) {

    vector<int> min_bits,max_bits;
    int carry;
    int _min = min(x,y);
    int _max = max(x,y);
    while(_min > 0){
        carry = _min % 2;
        _min = _min / 2;
        min_bits.push_back( carry );
    }
    while(_max > 0){ 
        carry = _max % 2;
        _max = _max / 2;
        max_bits.push_back( carry );
    }


    int max_len = max_bits.size();
    int min_len = min_bits.size();

    int distance = 0 ;
    for(int i=0;i<max_len;i++){
        if(i < min_len){
            if(max_bits[i] != min_bits[i]){
                distance += 1; 
            }
        }else{
            distance +=  max_bits[i];
        }
    }
    return distance;
}

int main(){

    int x = 1,y=4;
    cout << hammingDistance(x,y) << endl;
}
