#include<string>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        int base = 0;
        int res = 0;

        while (str[i] == ' ')
        i++;

        if (str[i] == '-')
        {
        sign = -1;
        i++;
        }
        else if (str[i] == '+')
        i++;


        while (str[i] >= '0' && str[i] <= '9'){
            if (base / 10 > INT_MAX / 10){
                if (sign == 1)
                return INT_MAX;
                else
                return INT_MIN;
            }
            else if (base / 10 == INT_MAX / 10 && str[i]-'0' > '7'){
                if (sign == 1)
                return INT_MAX;
                else
                return INT_MIN;
            }
            base = base * 10 + str[i]-'0';
            i++;
        }

        base = base * sign;
        return base;

    }
};


int main()
{

    string str = "1234";
    Solution s1;
    int val = s1.myAtoi(str);
    cout << val << endl;
    return 0;
}