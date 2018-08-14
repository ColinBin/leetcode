//
//  main.cpp
//  188_Best Time to Buy and Sell Stock IV
//
//  Created by Colin on 23/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int priceCount = prices.size();
    if(priceCount < 2 || k <= 0) return 0;
    if(k >= priceCount) {
        int totalProfit = 0; 
        for(int i = 1; i < priceCount; ++i) {
            int currDiff = prices[i] - prices[i - 1];
            if(currDiff > 0) totalProfit += currDiff;
        }
        return totalProfit;
    }
    vector<vector<int>> dp(priceCount + 1, vector<int> (k + 1, 0));
    for(int j = 1; j <= k; ++j) {
        int tempMax = -prices[0];
        for(int i = 1; i <= priceCount; ++i) {
            tempMax = max(tempMax, dp[i][j - 1] - prices[i - 1]);
            dp[i][j] = max(dp[i - 1][j], tempMax + prices[i - 1]);
        }
    }
    return dp[priceCount][k];
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
