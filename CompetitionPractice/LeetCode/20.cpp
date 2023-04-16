#include <string>
#include <stack>

using namespace std;

/*
Use stack to keep track of open brackets and iterate through string, 
until loop is finished or top of stack does not match a closed bracket

1. Loop through each character of stack
    - If character is an open bracket, add it to a stack
    - If character is a closed bracket, check if top of stack matches the closed bracket
        - If top character matches, pop the top from the stack
        - Otherwise, return false
2. Return true if stack is empty at the end of the loop
3. Otherwise, return false
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> storage;
        int stringlen = s.length();
    
        for (int i = 0; i < stringlen; i++) {
            // If current char is an open bracket, add it to stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                storage.push(s[i]);

            // If current char is a closed bracket
            else {
                // If top of stack does not match current char
                if (storage.empty() || (s[i] == ')' && storage.top() != '(') ||  (s[i] == ']' && 
                        storage.top() != '[') || (s[i] == '}' && storage.top() != '{'))
                    return false;
                
                // Otherwise, pop top from stack
                storage.pop();
            }
        }

        // Return true if stack is empty after loop
        return storage.empty();
    }
};