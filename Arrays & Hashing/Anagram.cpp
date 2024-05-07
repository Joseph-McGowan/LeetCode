//
// Created by josep on 07/05/2024.
//
#include <algorithm>
#include <iostream>
#include <string>
using std::string;

class Solution {
public:
    static bool isAnagram(string s, string t) {

        if(s.size() != t.size() )
            return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }

};


int main(int argc, char** argv) {

    //Solution a = new Solution;

    std::cout << Solution::isAnagram("hel", "hello") << std::endl;

    return 1;
}
