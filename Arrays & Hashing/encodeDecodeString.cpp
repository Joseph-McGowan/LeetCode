//
// Created by joseph on 27/06/2024.
//
#include "string"
#include "iostream"
#include "vector"
#include "set"
#include "map"

using namespace std;

class Solution {
public:


    static string encode(vector<string>& strs) {

        map<string, int> charMap;
        string encodedString;

        for (auto i : strs) {
            encodedString += to_string(i.size()) + "#" + i;
        }

        return encodedString;
    }

    static vector<string> decode(string s) {
        string word;
        vector<string> words;
        int i = 0;
        int j=  0;
        while (i < s.length()) {
            j = i;
            while (s[j] != '#' )
                j++;
            int wordLength = stoi(s.substr(i,j));
            words.push_back(s.substr(j + 1 , wordLength));
            i = j + 1 +  wordLength;

        }

        return words;
    }
};



int main() {

    vector <string> sVec = {"hello", "there", "world"};
    string s = "hello";

    cout << Solution::encode(sVec) << endl;
    s = Solution::encode(sVec);

    vector<string> answer = Solution::decode(s);

    for (auto i : answer)
        cout << i << endl;

    return 1;
}