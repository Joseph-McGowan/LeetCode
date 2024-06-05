//
// Created by josep on 04/06/2024.
//
#include <iostream>

#include "vector"
#include "algorithm"
#include "string"
#include "stack"
#include "cctype"
#include "math.h"

using namespace std;


class Solution {
public:
    static int evalRPN(vector<string>& tokens) {
        stack<int> vals;

        for (auto i : tokens) {
            if ((!isdigit(i[0])) && (i.length() == 1)) {
                if (vals.size() < 2)
                    break;
                int a = vals.top();
                vals.pop();
                int b = vals.top();
                vals.pop();
                switch (int(i[0])) {
                    case '+':
                        vals.push(a+b);
                        break;
                    case '-':
                        vals.push(b-a);
                        break;
                    case '*':
                        vals.push(a*b);
                        break;
                    case '/':
                        vals.push(floor(b/a));
                        break;

                }
            }
            else {
                vals.push(stoi(i));
            }

        }
        return vals.top();
    }
};


int main() {

    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    cout << Solution::evalRPN(tokens);

    return 0;
}