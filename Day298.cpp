#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Google.

A girl is walking along an apple orchard with a bag in each hand. She likes to pick apples from each tree as she goes along, but is meticulous about not putting different kinds of apples in the same bag.

Given an input describing the types of apples she will pass on her path, in order, determine the length of the longest portion of her path that consists of just two types of apple trees.

For example, given the input [2, 1, 2, 3, 3, 1, 3, 5], the longest portion will involve types 1 and 3, with a length of four.

*/

vector<int> arr;

string toString(int a){
    stringstream ss;
    string ans;
    ss << a;
    ss >> ans;
    return ans;
}

int solve(){

    /*

    EASY

    Solution: 

    This problem can be solved greedily.

    We can guard the number of times of a type A has appeared consecutively, same for type B.
    1 - If we have no type A yet, fill type A and guard his appearences.
    2 - If we have no type B yet and there is a new type, fill type B and guard his appearences.
    3 - If the i-th number of the array is not different than types A or B, just increment the counter and adjust the ocurriencies.
    
    4 - If the i-th number of the array is different than type A and B, then you have to see which type was the (i-1)-th number of the array.
    5 - If it was type B, then type A is the i-th number now and his ocurrencies is 1. Counter now is type B ocurrencies plus 1, and then you adjust type B ocurrencies to 0.
    Complexity: O(N), where N is the size of the array.
    6 - You will return to pass 3 eventually.
    
    Sample Input:
    8
    2 1 2 3 3 1 3 5

    Sample Output:
    1 3 4

    */
    pair<string, int> a, b, ansA, ansB;


    int ans = 0;
    int counter = 0;
    
    for(int i=0; i<arr.size(); i++){
        string arr_string = toString(arr[i]);
        string last_arr_string = toString(arr[i-1]);

        if(a.first.empty()){
            a.first = arr_string;
            a.second = 1;
            counter++;
        }else if(b.first.empty()){
            b.first = arr_string;
            b.second = 1;
            a.second = 0;
            counter++;
        }else if(arr_string==a.first){
            a.second++;
            b.second = 0;
            counter++;
        }
        else if(arr_string==b.first){
            b.second++;
            a.second = 0;
            counter++;
        }else{
            
            if(last_arr_string==a.first){
                b.first = arr_string;
                b.second = 1;
            }else if(last_arr_string==b.first){
                a.first = arr_string;
                a.second = 1;
            }

            counter = a.second+b.second;
        }

        if(counter>ans){
            ans = counter;
            ansA = a;
            ansB = b;
        }
    }

    cout << ansA.first << " " << ansB.second << " ";
    return ans;
}

int main () {

    int n;
    cin >> n;

    arr.resize(n);

    for(int i=0; i<n; i++) cin >> arr[i];

    cout << solve() << endl;

    return 0;
}