#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Google.

Given an array of integers, return a new array where each element in the new array is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1

*/

/*
MEDIUM

In order to solve the problem, we can save the original position of the number and the number in an array.
Then, we sort the array in increasing order.
In every step, it's possible to update a Segment Tree with 1 in the i-th position, to certify that we have a number there
we already passed. And, the answer for every i-th position is the query of elements that we already passed on the interval 
[i+1, N-1]. Just save the answer for every position in another array and print on the end.
 
The update and the query in the segment tree is log(N).

Complexity: O(N*log²(N)), where N is the size of the array.
*/

vector<pair<int, int> > arr;
vector<int> seg, ans;

void update(int node, int l, int r, int pos, int val){
    if(l>pos or r<pos)  return;

    if(l==r and l==pos){
        seg[node]+=val;
        return;
    }

    int mid = (l+r)>>1;

    update(2*node + 1, l, mid, pos, val);
    update(2*node + 2, mid+1, r, pos, val);

    seg[node] = seg[2*node + 1] + seg[2*node + 2];
}

int query(int node, int l, int r, int qL, int qR){
    if(l>qR or r<qL) return 0;

    if(l>=qL and r<=qR)
        return seg[node];
    
    int mid = (l+r)>>1;

    return query(2*node + 1, l, mid, qL, qR)
        + query(2*node + 2, mid+1, r, qL, qR);
}

int main () {

    int n;

    cin >> n;

    arr.resize(n);
    ans.resize(n);
    seg.resize(5*n);

    for(int i=0; i<n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        update(0, 0, n-1, arr[i].second, 1);
        ans[arr[i].second] = query(0, 0, n-1, arr[i].second+1, n-1);
    }

    for(int i=0; i<n; i++)
        cout << ans[i] << " ";
    
    cout << endl;


    return 0;
}