#include <queue>

using namespace std;

/*
Implement a stack using a queue where the front of the queue is the top of the stack

Push Function:
1. Add new number to back of queue
2. Rotate queue by moving front of queue to back
   until new number is at the front of the queue

Pop Function:
1. Remove front value of queue and return it

Top Function:
1. Return front value of queue

Empty Function:
1. Return the empty() call on queue
*/

class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    
    void push(int x) {
        // Add new number to back of queue
        q.push(x);

        // Rotate queue until new number is at the front of queue
        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // Save front value and pop it
        int ret = q.front();
        q.pop();

        // Return saved value
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};