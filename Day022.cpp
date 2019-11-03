#include <bits/stdc++.h>

using namespace std;

/*
This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), return the original sentence in a list. If there is more than one possible reconstruction, return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

/*
MEDIUM

On this problem, we can use a hash table to store the original words that you want to query on the string. 
The queries on the hash table are made in O(1).
Then, whenever we find a substring that is on the hash table, we print and search the next. 

Complexity: O(N), where N is the size of the string.
*/
unordered_set<string> mapping;


int main () {

    string str;
    cin >> str;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string a;
        cin >> a;
        mapping.insert(a);
    }

    string word;
    for(int i=0; i<str.size(); i++){
        word+=str[i];
        if(mapping.find(word)!=mapping.end()){
            cout << word << endl;
            word.clear();
        }
    }

    return 0;
}