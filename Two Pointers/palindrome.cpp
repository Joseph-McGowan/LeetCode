//
// Created by josep on 21/05/2024.
//
#include <inttypes.h>

#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    static bool isPalindrome(string s) {

        char * start = &s[0];
        char * end = &s.back();


        //cout << *start  << endl;

        while(*start != NULL) {
            start++;
            //cout<<*start << endl;
            cout<< *end << endl;
            end--;
        }
        //cout << *end << endl;
    }
};

int main() {
    string s = "hello";

    Solution::isPalindrome(s);

}