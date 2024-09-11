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
        vector<string> finalList;
        string current;
        stack<string> currentStack;

        Solution:appendChar(0,0,current, n, finalList);

        return finalList;
    };

    static void appendChar(int openN, int closedN, string& a, int n, vector<string>&stringList ) {
        if (openN == closedN && openN == n) {
            //fully formed bracket
            stringList.emplace_back(a);
            a.clear();
            openN = 0;
            closedN = 0;
            return;
        }

        if (openN < n) {
            a.append("(");
            appendChar(openN+1, closedN, a, n, stringList);
            a.pop_back();
        }

        if(closedN < openN) {
            a.append(")");
            appendChar(openN, closedN+1, a, n, stringList);
            a.pop_back();
        }

    }
};


int main() {
    auto a = Solution::generateParenthesis(2);
    for (auto i : a)
        cout << i << endl;

}
