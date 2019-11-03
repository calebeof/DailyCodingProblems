#include <bits/stdc++.h>

#define INF int (1e7)
using namespace std;


/*
This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
*/


string a, b;

int solve(int i, int j){

    /*
    EASY

    The Edit Distance is a dynamic programming algorithm.
    We can divide two strings and compare into subintervals, which we can compare adding and removing characters from both
    strings, in order to turn one string into another.

    Complexity: O(N*M), where N is the size of the first string and M is the size of the second string.
    */

    if(i==0) return j;
    if(j==0) return i;

    if(a[i-1] == b[j-1])
        return solve(i-1, j-1);
    
    int ans = INF;

    ans = min(ans, 1 + solve(i, j-1));
    ans = min(ans, 1 + solve(i-1, j));
    ans = min(ans, 1 + solve(i-1, j-1));

    return ans;
}

int main () {

    cin >> a >> b;

    cout << solve(a.size(), b.size()) << endl;
    
    return 0;
}