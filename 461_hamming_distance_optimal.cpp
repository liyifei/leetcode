#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int hammingDistance(int x, int y) {

    int dist = 0, n = x ^ y;
    while (n) {
        ++dist;
        n &= n - 1;
    }
    return dist;
}

int main(){

    int x = 1,y=4;
    cout << (x^y) << endl;
    cout << hammingDistance(x,y) << endl;
}
