#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Keep a map to hold matched characters and a set to hold used characters from the t string
Loop through strings and return false if there is a
character in s that maps to two characters in t or vice versa

1. For every character in the strings
    - If characters in s and t are not used, map s[i] to t[i] and add t[i] to used characters
    - If one of the characters is mapped to another character, return false
2. Return true when loop completes
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> matches;
        unordered_set<char> used;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            // Keep iterators in map and set to save runtime
            auto it = matches.find(s[i]);
            auto val = used.find(t[i]);

            // If s[i] and t[i] are not used
            if (it == matches.end() && val == used.end()) {
                matches[s[i]] = t[i];
                used.insert(t[i]);
            }

            // If only s[i] or t[i] is used or s[i] to maps to another character
            else if (it == matches.end() || val == used.end() || it->second != *val)
                return false;
        }

        return true;
    }
};