#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> storage;
        int stringlen = s.length();

        if (s[0] != '(' && s[0] != '[' && s[0] != '{')
            return false;

        storage.push(s[0]);
    
        for (int i = 1; i < stringlen; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                storage.push(s[i]);
                continue;
            }

            if (storage.empty() || (s[i] == ')' && storage.top() != '(') || (s[i] == ']' && storage.top() != '[') || (s[i] == '}' && storage.top() != '{'))
                return false;
            
            storage.pop();
        }

        if (storage.empty())
            return true;
        
        return false;
    }
};