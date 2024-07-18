//
// Created by josep on 05/06/2024.
//
#include "iostream"
#include "stack"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    static vector<string> generateParenthesis(int n) {
        vector<string> bracketString;
        stack<string> brakcetStack;
        int numberOfOpen = 0;
        int numberOfClosed = 0;


        for (int i = n; i > 0 ; i--) {
            for (int j = 0; j < i; j++) {
                brakcetStack.push(")");
                numberOfClosed++;
            }
            //int j = n - i;
            while(!brakcetStack.empty()) {
                if (numberOfClosed < n) {
                    brakcetStack.push(")");
                    numberOfClosed++;
                }
                else {
                    if (numberOfOpen != n) {
                        brakcetStack.push("(");
                        numberOfOpen++;
                    }

                }

                if ((numberOfOpen == numberOfClosed && numberOfOpen == n)) {
                    string s;
                    while (!brakcetStack.empty()) {
                        s += brakcetStack.top();
                        brakcetStack.pop();
                    }
                    bracketString.emplace_back(s);
                }
            }
        }
        return bracketString;
    }
};

int main() {
    auto a = Solution::generateParenthesis(2);
    for (auto i : a)
        cout << i << endl;

}
