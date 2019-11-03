#include <bits/stdc++.h>

using namespace std;

/*

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?

*/


bool solve(vector<int> &arr, int k){

    /*
    
    EASY

    We can use a hash table, which is an unordered_set in c++.
    We can verify if (k - arr[i]) is in the hash. 
    If it is, then is possible to have two have two numbers that can be add up to k.
    Else, we can insert arr[i] into the hash table, because arr[i] still can be one of the two numbers that we want.

    The complexity of the hash_table is O(1) per query, and we just need to pass the original array one time.

    Time Complexity: O(N).
    Space Complexity: O(N).
    */
    
    unordered_set<int> mapa;

    for(int i=0; i<arr.size(); i++){
        
        if(mapa.find(k-arr[i])!=mapa.end())
            return 1;

        mapa.insert(arr[i]);
    }
    
    return 0;
}

int main () {

    vector<int> arr = {10, 14, 3, 7};
    int k = 17;

    cout << (solve(arr, k) == 1 ? "true" : "false") << endl;
    return 0;
}