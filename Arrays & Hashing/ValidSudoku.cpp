//
// Created by joseph on 20/05/2024.
//
#include "vector"
#include "iostream"
#include "unordered_set"
#include "unordered_map"

using namespace std;



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        const int boardSize = 9;

        bool rows[boardSize][boardSize] = {false};
        bool cols[boardSize][boardSize] = {false};
        bool sub[boardSize][boardSize] = {false};

        for(int r = 0; r < boardSize; r++)
            for (int c = 0; c < boardSize; ++c) {
                char symbol = board[r][c];
                if(symbol == '.')
                    continue;
                else {
                    int idx = board[r][c] - '0' - 1; //char to int conversion
                    int area = (r/3) * 3 + (c/3);

                    if (rows[r] || cols[c] || sub[area][idx])
                        return false;
                    rows[r][idx] = true;
                    cols[c][idx] = true;
                    sub[area][idx] = true;

                }
            }
        return true;

    }
};