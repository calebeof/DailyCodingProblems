#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Amazon.

Given n numbers, find the greatest common denominator between them.

For example, given the numbers [42, 56, 14], return 14.

*/

int gcd(int a, int b){
    /*
    EASY

    In this problem, it's just required to execute the Euclid Algorithm to find the Greatest Commom Divisor between two numbers.
    If we apply the GCD between all numbers, we find the answer.

    Complexity: O(N*log(N)), where N is the size of the array.
    */
    if(b==0)
        return a;
    else return gcd(b, a%b);
}


int main () {

    int n;
    vector<int> arr;

    cin >> n;

    arr.resize(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    int ans = arr[0];

    for(int i=1; i<n; i++)
        ans = gcd(ans, arr[i]);
    
    cout << ans << endl;
    return 0;
}