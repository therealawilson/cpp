#include <ctype.h>
#include <string>
#include <iostream>

class Solution {
public:
    bool isPal(std::string s)
    {
        int front = 0;
        int back = s.size()-1;
        
        while (front <= back)
        {
            if (!isalnum(s[front]))
            {
                front++;
                continue;
            }
            if (!isalnum(s[back]))
            {
                back--;
                continue;
            }
            if (tolower(s[front]) == tolower(s[back]))
            {
                front++;
                back--;
            }
            else{
                return false;
            }
        
        }
        return true;
    }
};

int main()
{
    Solution s1;
    std::string str = "A man, a plan, a canal: Panama";
    if (s1.isPal(str))
    {
        std::cout << str << " -- is indeed a palandrome" << std:: endl;
    }
    else
    {
        std::cout << str << " -- is NOT a palandrome" << std::endl;
    }
    return 0;
}
