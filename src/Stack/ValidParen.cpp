//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
#include<string>
#include <iostream>
#include<stack>

using namespace std;

class Paren{
public:
    bool isValid(string& str)
    {
        stack<char> s;
        for (char i : str){
            if (i == '(' || i == '{' || i == '['){
                s.push(i);
            }

       
            if (s.empty())
            return false;
            if (i == ')' && s.top()!= '(')
            return false;
            if (i == '}' && s.top()!= '{')
            return false;
            if (i == ']' && s.top()!= '[')
            return false;

            s.pop();
        
        }
        return true;
    }
};

int main()
{
    Paren p1;
    string s1 = "(){}";

    if (p1.isValid(s1)){
        cout << "valid parens";
    }
    else{
        cout << "parens NOT valid";
    }

    return 0;
}