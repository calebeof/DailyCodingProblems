#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Google.

Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation, can you perform this operation in-place?

*/

/*
MEDIUM

Just accumulate a word and push into a vector of words when you find a space or after the line.

Then, just print the words in reversed order.

Complexity: O(N), where N is the size of the string (line).
*/

int main () {
    string line;

    getline(cin, line);

    vector<string> words;

    string word;

    for(int i=0; i<line.size(); i++){

        if(line[i]==' '){
            words.push_back(word);
            word.clear();
        }
        else word+=line[i];
    }

    words.push_back(word);
    
    for(int i=words.size()-1; i>=0; i--)
        cout << words[i] << " ";
    cout << endl;

    return 0;
}