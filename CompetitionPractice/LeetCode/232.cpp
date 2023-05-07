#include <stack>

using namespace std;

/*
Implement a queue using two stacks where the top of the main stack is the front of the queue

Push Function:
1. Shift everything to stack2
2. Add new number to stack1
3. Shift everything back to stack1

Pop Function:
1. Remove top value of stack and return it

Peek Function:
1. Return top value of stack

Empty Function:
1. Return the empty() call on stack
*/

class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;
    MyQueue() {}
    
    void push(int x) {
        // Shift everything to stack2
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        // Add new number to stack1
        stack1.push(x);
        
        // Shift everything back to stack1
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }
    
    int pop() {
        // Save top value and pop it
        int ret = stack1.top();
        stack1.pop();

        // Return saved value
        return ret;
    }
    
    int peek() {
        return stack1.top();
    }
    
    bool empty() {
        return stack1.empty();
    }
};