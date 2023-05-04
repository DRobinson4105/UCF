#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> matches;
        unordered_set<char> used;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            auto it = matches.find(s[i]);
            auto val = used.find(t[i]);
            if (it == matches.end() && val == used.end()) {
                matches[s[i]] = t[i];
                used.insert(t[i]);
            }
            else if (it == matches.end() || val == used.end() || it->second != *val)
                return false;
        }

        return true;
    }
};