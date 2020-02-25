#include <bits/stdc++.h>

using namespace std;

/*This problem was asked by Indeed.

Given a 32-bit positive integer N, determine whether it is a power of four in faster than O(log N) time.*/

int main () {

    int n;
    cin >> n;

    /*
    MEDIUM
    
    Solution:
    We have to see if there is only one bit set on the representation in powers of 4. 
    
    Complexity: O(log4(N)).
    */
    int countOne = 0;
    
    while(n>0){

        if(n%4>=1 and countOne){
            cout << "N" << endl;
            return 0;
        }

        if(n%4==1) countOne++;
        n/=4;
    }

    if(countOne==0) cout << "N" << endl;
    else cout << "Y" << endl;
    return 0;
}