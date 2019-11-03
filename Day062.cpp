#include <bits/stdc++.h>

#define TAM 1000

using namespace std;

/*

This problem was asked by Facebook.

There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at the top-left corner and getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:

Right, then down
Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.

*/

/*

MEDIUM

This is a classical counting dp problem, which we count the ways to get into a position.
Beginning with the position (1,1), we can recursively call the two moves possible in each position we go.
Whenever we go to the position (n, m), we return 1 (that means that we found a way to get into bottom right corner)
and continue the process.
In the end, we will have the ways can come to (n, m).

Since we have to calculate the position (i, j) a lot of times, the dynamic programming technique appears, as we save 
the calculation in every step and reuse it.

Pay attention to the axis limits and the large size of the answer.

Complexity:O(N*M), where N and M are the dimensions of the matrix.
*/


int n, m;

vector<vector<long long int> > dp(TAM, vector<long long int> (TAM, -1LL));

long long int solve(int i, int j){

    if(i==n and j == m)
        return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    long long int ans = 0;

    if(i+1<=n)
        ans+=solve(i+1,j);
    if(j+1<=m)
        ans+=solve(i, j+1);

    return dp[i][j] = ans;
}

int main () {

    cin >> n >> m;

    cout << solve(1, 1) << endl;
    return 0;
}