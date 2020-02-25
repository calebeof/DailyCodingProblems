#include <bits/stdc++.h>

#define INF int (1e7)
using namespace std;


/*
This problem was asked by Microsoft.

The transitive closure of a graph is a measure of which vertices are reachable from other vertices. It can be represented as a matrix M, where M[i][j] == 1 if there is a path between vertices i and j, and otherwise 0.

For example, suppose we are given the following graph in adjacency list form:

graph = [
    [0, 1, 3],
    [1, 2],
    [2],
    [3]
]
The transitive closure of this graph would be:

[1, 1, 1, 1]
[0, 1, 1, 0]
[0, 0, 1, 0]
[0, 0, 0, 1]
Given a graph, find its transitive closure.

*/


vector<vector<int> > graph;
vector<vector<bool> > closure;
vector<bool> mark;
int n, m;

void sum(vector<bool> &closureA, vector<bool> &closureB){
    for(int i=0; i<closureA.size(); i++)
        if(closureB[i])
            closureA[i]=1;
}

void solve(int vertex){

    /*
    EASY

    This problem can be solved by brute force:
    Do DFS traversal in the graph and sum the closure lists between the current vertex
    and his adjacencies. 

    4 7
    0 0
    0 1
    0 3
    1 1
    1 2
    2 2
    3 3
    (example of the problem)
    Complexity: O(N²), from the N*DFS.
    */

    mark[vertex] = 1;

    for(int i=0; i<graph[vertex].size(); i++){
        int adj = graph[vertex][i];
        if(!mark[adj]){
            solve(adj);
            sum(closure[vertex], closure[adj]);
        }
    }

}

int main () {

    cin >> n >> m;
    mark.resize(n);

    graph.resize(n, vector<int>());
    closure.resize(n, vector<bool> (n, false));

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        closure[a][b] = true;
    }

    for(int i=0; i<n; i++)
        if(!mark[i]) solve(i);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout << closure[i][j] << " ";
        cout << endl;
    } 
    return 0;
}