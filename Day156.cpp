#include <bits/stdc++.h>

#define INF int(1e8)
using namespace std;


/*

This problem was asked by Facebook.

Given a positive integer n, find the smallest number of squared integers which sum to n.

For example, given n = 13, return 2 since 13 = 32 + 22 = 9 + 4.

Given n = 27, return 3 since 27 = 32 + 32 + 32 = 9 + 9 + 9.

*/

/*
MEDIUM

In this problem, a dinamic programming approach can be made if we test every single number i that (when it is squared) is 
smaller than N. So, we subtract N by (i*i) and continue the process until we fall to the base case N<=1, where we return N.
Then, it is returned the minimum steps required to get into the base case.

The recursion also can be:
f(N) = min(f(N-(i*i))), where i is [1, sqrt(N)],
f(N) = 0, where N = 0,
f(N) = 1, where N = 1,
f(N) = 2, where N = 2,
f(N) = 3, where N  = 3.

Complexity: O(N²), where N is the number that we want to know.

*/
vector<int> dp;
int solve(int n){
    if(n<=1)
        return n;

    if(dp[n]!=-1) return dp[n];

    int ans = INF;
    
    for(int i=sqrt(n); i>=1; i--)
        ans = min(1+solve(n-(i*i)), ans);
    
    return dp[n] = ans;
}

int main () {
    int n;
    cin >> n;

    dp.resize(n+1, -1);
    cout << solve(n) << endl;

    return 0;
}