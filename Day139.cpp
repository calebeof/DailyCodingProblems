#include <bits/stdc++.h>

#define EPS 1e-6
#define LARGE 1e8

using namespace std;

/*

Given a real number n, find the square root of n. For example, given n = 9, return 3.

*/

double solve(double num){

    /*

    MEDIUM

    We can do a binary search to find the number A, where A*A = N. 
    The left corner of our binary search starts with zero, and the right corner starts with the number itself.
    Then, we need an EPS good enough to treat with our precision. Here, we can choose 10^-6.

    When A*A is larger then N, we do r = mid.
    When A*A + EPS is less then N, we do l = mid.

    And when N - (A*A) < EPS, we find the number that can be the square root of N.

    Complexity: O(log(N)), where N is the real number we have to find the square root.

    */

    double l = 0, mid, r = num;

    while(l<=r){
        
        mid = (l+r)/2;

        if(num - (mid*mid) < EPS and num - (mid*mid) > 0)
            break;
        else if(num - (mid*mid) > EPS)
            l = mid;
        else if(num - (mid*mid) < 0)
            r = mid;

    }
    
    return mid;
}

int main () {

    double num;

    cin >> num;
    
    cout << solve(num) << endl;
    return 0;
}