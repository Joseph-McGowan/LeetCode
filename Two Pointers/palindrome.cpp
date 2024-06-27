//
// Created by josep on 21/05/2024.
//
#include <inttypes.h>
#include <string.h>
#include "cctype"

#include "string"
#include "iostream"

using namespace std;

class Solution {
public:
    static bool isPalindrome(string s) {

        int leftPointer = 0;
        int rightPointer = s.length() - 1;

        while(rightPointer > leftPointer) {
            if (!isalnum(s[leftPointer]) && leftPointer < rightPointer) { //ascii space = 32
                leftPointer++;
                continue;
            }

            if (!isalnum(s[rightPointer]) && rightPointer > leftPointer) {
                rightPointer--;
                continue;
            }

            if (tolower(s[leftPointer]) != tolower(s[rightPointer]))
                return false;
            else {
                rightPointer--;
                leftPointer++;
            }
        }

        return true;



//        for  (int i = 0; i < s.size(); i++) {
//            char x = s[i];
//            if (!std::isalnum(x)) {
//                s.erase(i, 1);
//                i--;
//                continue;
//            }
//            s[i] = tolower(s[i]);
//        }
//
//        int start = 0 ;
//        int end = s.size() - 1;
//
//        while(start <= end) {
//            if (s[start] != s[end])
//                return false;
//            start++;
//            end--;
//        }
//        return true;
    }
};

int main() {
    string s = "0P";

    cout << Solution::isPalindrome(s);

}