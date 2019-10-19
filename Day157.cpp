#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Google.

Given a string, return the first recurring character in it, or null if there is no recurring character.

For example, given the string "acbbac", return "b". Given the string "abcdef", return null.

*/

char solve(string &str){

    /*
    
    EASY
    
    We can greedly count the characters that are appearing in the string with an auxiliary array.
    The first character that appears twice is returned. 

    If no character appears twice, then we return null character.

    Complexity: O(N), where is the size of the string.
    
    */

    vector<int> counter(26, 0);
    
    for(int i=0; i<str.size(); i++){
        counter[str[i]-'a']++;

        if(counter[str[i]-'a']>1)
            return str[i];

    }

    return '\0'; //NULL
}

int main () {
    string str;
    
    cin >> str;

    cout << solve(str) << endl;

    return 0;
}