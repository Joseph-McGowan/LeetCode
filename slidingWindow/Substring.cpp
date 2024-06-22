//
// Created by josep on 21/06/2024.
//

#include "string.h"
#include "iostream"
#include "hash_set"
#include "unordered_set"

using namespace std;

class Solution {
public:
   static int lengthOfLongestSubstring(string s) {

       //set containg current chars of substring
       //current length variable
       //if new substring longer, = longest
       //if repeat counter found, reset counter, char set
       //return longest substring



       unordered_set<int> sbstrList;
       int currentLength = 0;
       int longest = 0;
       int leftPointer = 0;
       int rightPointer = 0;

       for(int i = 0; i < s.length(); i++) {

           if (!sbstrList.count(s[i])) {
               sbstrList.emplace(s[i]);
               currentLength++;
               if (currentLength > longest) {
                   longest = currentLength;
               }
           }
           else {
               while (s[leftPointer] != s[i]) {
                    sbstrList.erase(s[leftPointer]);
                   leftPointer++;
                   currentLength--;
               }
               leftPointer++;
           }
       }

       return longest;


    }
};



int main() {

    string a = "tmmzuxt";
    cout << Solution::lengthOfLongestSubstring(a) << endl;

}
