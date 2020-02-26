#include <bits/stdc++.h>

using namespace std;

/*
This problem was asked by Uber.

On election day, a voting machine writes data in the form (voter_id, candidate_id) to a text file. Write a program that reads this file as a stream and returns the top 3 candidates at any given time. If you find a voter voting more than once, report this as fraud.
*/


/*

EASY

Solution:

Just brute force by query and save the votes on maps. Remember to check frauds with another map.

Complexity: O(Q*(N*log(N))), where Q is the number of queries and N is the number of votes.

*/

map<string, int> counter_voter, counter_candidate;

pair<string, string> parseLine(string line){
    int i;
    string voter, candidate;

    for(i=1; i<line.size(); i++){
        if(line[i]==',')
            break;
        voter+=line[i];
    }

    for(i+=1; i<line.size()-1; i++)
        candidate+=line[i];
    
    return make_pair(voter, candidate);
}

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second>b.second;
}

void top_three(){
    vector<pair<string, int> > rank;

    for(auto it = counter_candidate.begin(); it!=counter_candidate.end(); it++)
        rank.push_back(make_pair(it->first, it->second));
    
    sort(rank.begin(), rank.end(), comp);

    for(int i=0; i<min((int)rank.size(), 3); i++)
        cout << rank[i].first << " " << rank[i].second << endl;
}

int main () {
    ifstream arq("file.txt", ifstream::in);

    string vote;

    while(getline(arq, vote)){
        pair<string, string> voter_candidate = parseLine(vote);
        string voter, candidate;

        voter = voter_candidate.first;
        candidate = voter_candidate.second;

        counter_voter[voter]+=1;
        
        if(counter_voter[voter]>1){
            cout <<"FRAUD" << endl;
            return 0;
        }

        counter_candidate[candidate]+=1;

        top_three();
    }

    return 0;
}