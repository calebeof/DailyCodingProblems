#include <bits/stdc++.h>

using namespace std;

/*
This problem was asked by Bloomberg.

Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
*/

bool solve(string s1, string s2){

    /*

    EASY
    
    We can map greedly every i-th character of s1 with the i-th character of s2. 
    If, during this routine, we have two maps for one character, we return false.
    Else, then the map is possible.

    Complexity: O(N), where N is the size of the strings. 

    */

    vector<int> mapa(26, -1);

    for(int i=0; i<s1.size(); i++){
        int a = s1[i]-'a';
        int b = s2[i]-'a';

        if(mapa[a]==-1)
            mapa[a] = b;
        else if(mapa[a]!=-1 and mapa[a]!=b)
            return false;

    }

    return true;
}


int main () {

    string s1, s2;

    cin >> s1 >> s2;

    cout << (solve(s1, s2)== true ? "true" : "false") << endl;

    return 0;
}