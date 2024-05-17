//
// Created by josep on 16/05/2024.
//
#include "iostream"
#include <vector>
#include "string"
#include "algorithm"
#include "unordered_map"

class Solution {
public:
    static std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> occurences;

        //sort words into alphabetical order
        std::vector<std::string>tempStorage;
        for (auto& c :strs)
            tempStorage.push_back(c);

        for (auto &c : strs) {
            std::sort(c.begin(), c.end() );

            //std::cout << c << std::endl;
        }

        for (int i = 0; i < strs.size(); i++) {
            std::string currentWord = strs[i];
            std::sort(currentWord.begin(), currentWord.end());
            if ( occurences.count(currentWord) == 0) {
                occurences.insert({currentWord, {tempStorage[i]}});
            }
            else (occurences.at(currentWord).emplace_back(tempStorage[i]));
        }

        std::vector<std::vector<std::string>> finalVals;

        for (auto& c : occurences)
            finalVals.emplace_back(c.second);

        // for (auto& c : finalVals)
        //     for (auto & b: c)
        //         std::cout << b << std::endl;

        return finalVals;
        //add each occurance of string pattern into a hast table, increment value accordingly
    }


};

int main() {

    std::vector<std::string> testString = {"eat","tea","tan","ate","nat","bat"};

    Solution::groupAnagrams(testString);
    return 0;
}