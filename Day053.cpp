#include <bits/stdc++.h>

using namespace std;

/*

This problem was asked by Apple.

Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.
*/

/*

MEDIUM

Whenever we have to enQueue a number, we push all the first stack into the second stack.
Then, we push the number into the first stack and push all the second stack into the first stack again.

Whenever we have to pop a number from the queue, just pop the top of the first stack.

Complexity: O(N*K), where N is the size of the queue and K is the operations on the queue.

*/

stack<int> sFirst, sSecond;

int main () {

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int op, number;
        cin >> op;
        if(op==0) //enQueue
        {
            cin >> number;

            while(sFirst.size()>0){
                sSecond.push(sFirst.top());
                sFirst.pop();
            }

            sFirst.push(number);

            while(sSecond.size()>0){
                sFirst.push(sSecond.top());
                sSecond.pop();
            }
        }
        else{ //deQueue
            if(sFirst.empty()){
                cout << "empty" << endl;
                continue;
            }

            cout << sFirst.top() << endl;
            sFirst.pop();
        }
    }
    return 0;
}