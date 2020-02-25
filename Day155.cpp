#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by MongoDB.

Given a list of elements, find the majority element, which appears more than half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], retur

*/
vector<int> lst;

int solve(){

    /*

    MEDIUM

    Solution:
    This problem can be easily solved using a map to count the times each number appeared.
    We verify just the number that appeared most in one pass.
    
    Complexity: O(N*log(N)).
    
    */

    map<int, int> count;
    int maxCount = -1, number = -1;

    for(int i=0; i<lst.size(); i++){
        count[lst[i]]++;
        if(count[lst[i]]>maxCount){
            maxCount = count[lst[i]];
            number = lst[i];
        }
    }

    return number;
}

int main () {
    int n;
    cin >> n;

    lst.resize(n);

    for(int i=0; i<n; i++) cin >> lst[i];

    cout << solve() << endl;
    return 0;
}