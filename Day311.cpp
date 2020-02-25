#include <bits/stdc++.h>

#define INF int (1e7)
using namespace std;


/*
This problem was asked by Sumo Logic.

Given an unsorted array, in which all elements are distinct, find a "peak" element in O(log N) time.

An element is considered a peak if it is greater than both its left and right neighbors. It is guaranteed that the first and last elements are lower than all others.
*/


vector<int> arr;
int n;

int solve(){

    /*
    EASY

    This problem can be solved using binary search. 
    The conditions to left and right pointers of the binary search are:
    if arr[mid+1]>arr[mid], then arr[mid+1] (or the right sub-array) can be a peak.
    if arr[mid-1]>arr[mid], then arr[mid-1] (or the left sub-array) can be a peak.
    
    The fact that the first and the last numbers of the array are the mininum values guarantee that this approach is valid.

    Complexity: O(log(N)), from the binary search.
    */

    int l = 1, r = n-2;
    int mid;
    while(l<r){
        mid = (l+r)/2;
        
        if(mid==n-1) break;
        if(mid==0) break;

        if(arr[mid-1]<arr[mid] and arr[mid]>arr[mid+1])
            break;
        
        if(arr[mid+1]>arr[mid])
            l = mid+1;
        else 
            r = mid-1;
    }

    return mid;
}

int main () {

    cin >> n;

    arr.resize(n);
    
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << solve() << endl;
    return 0;
}