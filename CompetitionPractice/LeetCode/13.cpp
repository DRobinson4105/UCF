#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int stringlen = s.length();
        for (int i = 0; i < stringlen; i++)
        {
            switch(s[i])
            {
                case 'M':
                    sum += 1000;
                    break;

                case 'D':
                    sum += 500;
                    break;

                case 'C':
                    if (i < stringlen - 1 && s[i + 1] == 'M')
                    {
                        sum += 900;
                        i++;
                        break;
                    }
                    if (i < stringlen - 1 && s[i + 1] == 'D')
                    {
                        sum += 400;
                        i++;
                        break;
                    }
                    sum += 100;
                    break;

                case 'L':
                    sum += 50;
                    break;

                case 'X':
                    if (i < stringlen - 1 && s[i + 1] == 'C')
                    {
                        sum += 90;
                        i++;
                        break;
                    }
                    if (i < stringlen - 1 && s[i + 1] == 'L')
                    {
                        sum += 40;
                        i++;
                        break;
                    }
                    sum += 10;
                    break;

                case 'V':
                    sum += 5;
                    break;

                case 'I':
                    if (i < stringlen - 1 && s[i + 1] == 'X')
                    {
                        sum += 9;
                        i++;
                        break;
                    }
                    if (i < stringlen - 1 && s[i + 1] == 'V')
                    {
                        sum += 4;
                        i++;
                        break;
                    }
                    sum += 1;
                    break;
            }
        }

        return sum;
    }
};