#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Twitter.

Given a list of numbers, create an algorithm that arranges them in order to form the largest possible integer. For example, given [10, 7, 76, 415], you should return 77641510.

*/

vector<int> arr;

string toString(int a){
    string res;
    stringstream ss;
    ss << a;
    ss >> res;
    return res;
}

bool comp(int a, int b){
    string A = toString(a);
    string B = toString(b);

    for(int i=0; i<min(A.size(), B.size()); i++)
        if(A[i]!=B[i])
            return A[i]>B[i];
    
    return A.size()<B.size();
}

int solve(){

    /*

    MEDIUM
    
    Solution:
    
    We have a greedy approach to this problem. Just sort the array prioritizing the bigger digits from the left.
    If the comparation by digits it's over and the number A is bigger (in number of digits) than the number B, prioritize number B.

    Then, just accumulate the numbers in the order of the resulting array. 

    Example of input:
    4
    10 7 76 415

    Example of output: 
    77641510

    Complexity: O(N*log(N) + N).
    */
    sort(arr.begin(), arr.end(), comp);
    int newNumber = 0;

    for(int i=0; i<arr.size(); i++){
        if(i==0)
            newNumber+=arr[i];
        else{
            newNumber*=pow(10, (toString(arr[i]).size()));
            newNumber+=arr[i];
        }
    }

    return newNumber;
}
int main () {
    int n;
    cin >> n;

    arr.resize(n);
    
    for(int i=0; i<n; i++)  cin >> arr[i];

    cout << solve() << endl;
    return 0;
}