cmake_minimum_required(VERSION 3.28)
project(LeetCode)

set(CMAKE_CXX_STANDARD 17)

#Arrays and Hashing Solutions
add_executable(Anagram "Arrays & Hashing/Anagram.cpp")
add_executable(test "Arrays & Hashing/test.cpp")
add_executable(twoString "Arrays & Hashing/twoSum.cpp")
add_executable(GroupAnagram "Arrays & Hashing/GroupAnagram.cpp")

#... solutions


add_executable(kFrequentElements "Arrays & Hashing/kFrequentElements.cpp")
add_executable(productExceptSelf "Arrays & Hashing/productExceptSelf.cpp")
add_executable(ValidSudoku "Arrays & Hashing/ValidSudoku.cpp")
add_executable(longestConscutive "Arrays & Hashing/longestConscutive.cpp")
add_executable(palindrome "Two Pointers/palindrome.cpp")
add_executable(twoSumII "Two Pointers/twoSumII.cpp")
add_executable(threeSum "Two Pointers/threeSum.cpp")
add_executable(Rpn "Stack/Rpn.cpp")
add_executable(genParenthesis Stack/genParenthesis.cpp)
add_executable(stocks slidingWindow/stocks.cpp)
add_executable(Substring slidingWindow/Substring.cpp)
add_executable(LongestRepeatingChar slidingWindow/LongestRepeatingChar.cpp)
add_executable(binarySearch binSearch/binarySearch.cpp)
add_executable(containerMax "Two Pointers/containerMax.cpp")
add_executable(trappingWater "Two Pointers/trappingWater.cpp")
add_executable(encodeDecodeString "Arrays & Hashing/encodeDecodeString.cpp")
add_executable(dailyTemp Stacks/dailyTemp.cpp)