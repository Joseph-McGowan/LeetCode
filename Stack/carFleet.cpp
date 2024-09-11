//
// Created by joseph on 11/09/2024.
//

#include "vector"
#include "stack"
#include "iostream"

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int noFleets = position.size();

        while(!position.empty()) {
            for (int i = 0; i < position.size(); i++) {
                position[i] += speed [i];
            }
            for (int )

        }


    }
};


int main() {

}