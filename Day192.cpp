#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Google.

You are given an array of nonnegative integers. Let's say you start at the beginning of the array and are trying to advance to the end. You can advance at most, the number of steps that you're currently on. Determine whether you can get to the end of the array.

For example, given the array [1, 3, 1, 2, 0, 1], we can go from indices 0 -> 1 -> 3 -> 5, so return true.

Given the array [1, 2, 1, 0, 0], we can't reach the end, so return false.

*/

vector<int> arr, dp;

bool solve(int current){

    /*

    MEDIUM

    In this problem, the idea is to find a valid path that reaches the end using the steps that we have available on the position that we are currently on.
    So, it is necessary to test every possible number of steps that is available, and choose any that can reach our goal.

    We can build a recursion and save the results, solving the problem with dynamic programming.

    Complexity: O(N*K), where N is the size of the array and K is the maximum number that appears.
    */

    if(current>=arr.size()) return true;

    if(dp[current]!=-1) return dp[current];

    bool ok = 0;

    for(int i=1; i<=arr[current]; i++)
        ok|=solve(current+i);
    
    return dp[current] = ok;
}


int main () {

    int n;
    cin >> n;

    arr.resize(n);
    dp.resize(n, -1);

    for(int i=0; i<n; i++) cin >> arr[i];

    cout << (solve(0) == true ? "true" : "false") << endl;

    return 0;
}