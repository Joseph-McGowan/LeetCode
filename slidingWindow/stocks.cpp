//
// Created by josep on 06/06/2024.
//
#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {

        if (prices.size() < 2)
            return 0;

        int bestBuyIndex = 0;
        int bestSellIndex = 1;

        int bestBuy = prices[0];
        int bestSell = prices[1];

        int index = 0;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < bestBuy && i <= bestSellIndex) {
                //best time to buy
                bestBuy = prices[i];
                bestBuyIndex = i;
            }
            for (int j = i; j < prices.size(); j++) {
                if (prices[j] > bestSell && j > bestBuyIndex || (prices[j] == bestSell && bestSellIndex < j)) {
                    bestSell = prices[j];
                    bestSellIndex = j;
                }
            }
        }


        if ((bestSell - bestBuy) <  0)
            return 0;
        return {bestSell - bestBuy};
    }
};

int main() {

    vector<int> a = {3,3,5,0,0,3,1,4};
    auto b = Solution::maxProfit(a);

    cout << b;
}