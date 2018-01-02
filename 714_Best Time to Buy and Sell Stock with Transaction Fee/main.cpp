//
//  main.cpp
//  714_Best Time to Buy and Sell Stock with Transaction Fee
//
//  Created by Colin on 01/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int priceCount = prices.size();
    int sell = 0, buy = -prices[0];;
    for(int i = 1; i <= priceCount; ++i) {
        int newBuy = max(buy, sell - prices[i - 1]);
        int newSell = max(sell, buy + prices[i - 1] - fee);
        buy = newBuy;
        sell = newSell;
    }
    return sell;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
