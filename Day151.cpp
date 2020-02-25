#include <bits/stdc++.h>

using namespace std;

/*

Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

B B W
W W W
W W W
B B B


Becomes

B B G
G G G
G G G
B B B

*/

int X;
int Y;

vector<string> graph;

void DFS(int x, int y, char newChar, char oldChar){

    /*

    MEDIUM

    Solution:

    Classic problem of graph traversal. Just do a DFS in the coordinate of the matrix and traverse on the adjancies until
    find a different character than the old one.

    Sample input:

    4 3
    B B W
    W W W
    W W W
    B B B
    2 2 G

    Sample output:
    4 3
    B B W
    W W W
    W W W
    B B B
    2 2 G

    Complexity: O(N+M);
    
    */

    graph[x][y] = newChar;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int i=0; i<4; i++){
        int newX = x+dx[i];
        int newY = y+dy[i];

        if(newX>=0 and newX<X and newY>=0 and newY<Y){
            if(graph[newX][newY]==oldChar)
                DFS(newX, newY, newChar, oldChar);
        }
    }
}


int main () {
    cin >> X >> Y;

    graph.resize(X);

    for(int i=0; i<X; i++){
        string cur;
        for(int j=0; j<Y; j++){
            char o;
            cin >> o;
            cur+=o;
        }
        graph[i] = cur;
    }

    int posX, posY;
    char newChar;
    cin >> posX >> posY >> newChar;

    DFS(posX, posY, newChar, graph[posX][posY]);

    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    return 0;
}