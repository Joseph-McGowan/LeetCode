//
// Created by joseph on 03/06/2024.
//
#include "iostream"
#include "algorithm"
#include "stack"

using namespace std;


class Solution {
public:
    static bool isValid(string s) {

        stack<char> validIn;

        for (auto i : s) {
            if (i == '(' || i == '{' || i == '[') {
                validIn.push(i);
            }

            else if((i == ']' || i == '}' || i == ')') && !validIn.empty()) {
                char compare = validIn.top();
                validIn.pop();
                if (i == ']' && compare != '[')
                    return false;
                else if (i == '}' && compare != '{')
                    return false;
                else if (i == ')' && compare != '(')
                    return false;

            }
            else
                return false;
        }
        if (validIn.empty())
            return true;
        return false;



    }
};


int main() {
    cout << Solution::isValid("]");
}