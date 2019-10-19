#include <bits/stdc++.h>

#define FREE 1
#define OCCUPIED 2
#define ATTACKED 3

using namespace std;

/*

This problem was asked by Google.

On our special chessboard, two bishops attack each other if they share the same diagonal. This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard. Write a function to count the number of pairs of bishops that attack each other. The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)
The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.

*/

int n, m;

int dfs(pair<int, int> actual, vector<vector<int> > &mark){
    /*
    
    MEDIUM

    Each bishop cell can be viewed as three states:
    
    1 - FREE, we didn't use that bishop before;
    2 - OCCUPIED, we did use that bishop before;
    3 - ATTACKED, that bishop is under attack.

    Then, we can treat each cell as a node of an undirected graph and see the diagonals that have other bishops.
    If we find a bishop that is free, we add 1 pair of bishops that are attacking themselves and recur on that bishop.
    At the end, we just return the pair of bishops that i-th bishop found.

    The answer is the sum of pairs that we encountered by running the Depth First Search for each bishop.

    Complexity: O(M*M), where M is the dimension of the chessboard.

    */

    int x = actual.first;
    int y = actual.second;

    int ans = 0;


    //up left

    int X = x;
    int Y = y;
    while(X>=0 and Y>=0){

        if(mark[X][Y]==FREE){
            mark[X][Y] = ATTACKED;
            mark[x][y] = ATTACKED;
            ans+=1+dfs(make_pair(X, Y), mark);
        }

        X--, Y--;
    }

    //up right

    X = x;
    Y = y;
    while(X>=0 and Y<m){
        if(mark[X][Y]==FREE){
            mark[X][Y] = ATTACKED;
            mark[x][y] = ATTACKED;
            ans+=1+dfs(make_pair(X, Y), mark);
        }

        X--, Y++;
    }

    //bottom left

    X = x;
    Y = y;
    while(X<m and Y>=0){
        if(mark[X][Y]==FREE){
            mark[X][Y] = ATTACKED;
            mark[x][y] = ATTACKED;
            ans+=1+dfs(make_pair(X, Y), mark);
        }

        X++, Y--;
    }

    //bottom right

    X = x;
    Y = y;
    while(X<m and Y<m){
        if(mark[X][Y]==FREE){
            mark[X][Y] = ATTACKED;
            mark[x][y] = ATTACKED;
            ans+=1+dfs(make_pair(X, Y), mark);
        }

        X++, Y++;
    }


    return ans;

}

int main () {

    cin >> n >> m;

    vector<vector<int> > mark(m, vector<int>(m, 0));
    vector<pair<int, int> > bishops;

    for(int i=0; i<n; i++){

        int x, y;
        cin >> x >> y;

        mark[x][y] = FREE;

        bishops.push_back(make_pair(x, y));

    }


    int answer = 0;

    for(int i=0; i<bishops.size(); i++){
        if(mark[bishops[i].first][bishops[i].second]==FREE){
            
            mark[bishops[i].first][bishops[i].second] = OCCUPIED;
            
            answer+=dfs(bishops[i], mark);
        }
    }

    
    cout << answer << endl;

    return 0;
}