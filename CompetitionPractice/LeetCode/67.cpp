#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {    
        if(b.size() > a.size()) swap(a,b);
        
        int aLength = a.size();
        int bLength = b.size();

        while(bLength < aLength)
        {
            b = "0" + b;
            bLength++;
        }

        int carry = 0;
        string res = "";

        for(int i = bLength; i >= 0 ; --i)
        {
            if(b[i] == '1' && a[i]=='1')
            {
                if(carry == 0) res = "0" + res;

                else res = "1" + res;
                    
                carry = 1;
            }

            else if(b[i] =='0' && a[i] =='0')
            {

                if(carry == 0) res = "0" + res;
                 
                else
                {
                    res = "1" + res;
                    carry = 0;
                }

            }

            else if((b[i]=='0' && a[i]=='1') || (b[i]=='1' && a[i] == '0'))
            {
                 
                if(carry == 0) res = "1" + res;
                 
                else res = "0" + res;
            }
        }
        
        if(carry == 1) res = "1" + res;
        
        return res;
    }
};