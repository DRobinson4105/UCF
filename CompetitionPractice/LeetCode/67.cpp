#include <iostream>

using namespace std;

/*
Add the two binary numbers from left to right, keeping
a carry flag and adding the result to a string

1. Add 0's to the beginning of the smaller string until the strings are the same size
2. From right to left, check values in strings
    - If both values are 1:
        - If carry is 0, add 0 to beginning of result
        - If carry is 1, add 1 to beginning of result
    - If one value is 1:
        - If carry is 0, 
*/

class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
      if (i >= 0)
        carry += a[i--] - '0';
      if (j >= 0)
        carry += b[j--] - '0';
      ans += carry % 2 + '0';
      carry /= 2;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};