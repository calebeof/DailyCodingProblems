#include <bits/stdc++.h>

#define EPS 1e-6
#define LARGE 1e8

using namespace std;

/*

This problem was asked by Amazon.

Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].

*/

void pushVector(vector<int> &A, vector<int> &B){

    for(int i=0; i<B.size(); i++)
        A.push_back(B[i]);

}

vector<int> solve(vector<int> arr, int x){

    /*

    MEDIUM
    
    This problem can be solved with 4 arrays:
    - The first one can get the numbers that are less then x;
    - The second one can get the numbers that are equal to x;
    - The third one can get the numbers that are larger than x;
    - The fourth one is the one who is the sequence of the others three arrays. 

    Then, the answer is just the fourth array.

    Complexity: O(N), where N is the size of the original array.

    */

    vector<int> A, B, C, answer;

    for(int i=0; i<arr.size(); i++){

        if(arr[i]<x)
            A.push_back(arr[i]);
        else if(arr[i]==x)
            B.push_back(arr[i]);
        else
            C.push_back(arr[i]);

    }

    pushVector(answer, A);

    pushVector(answer, B);

    pushVector(answer, C);
    
    return answer;
}


int main () {
    
    vector<int> arr = {9, 12, 3, 5, 14, 10, 10};
    int x = 10;

    vector<int> answer = solve(arr, x);
    
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << " ";
    cout << endl;

    return 0;
}