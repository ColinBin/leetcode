//
//  main.cpp
//  122_Best Time to Buy and Sell Stock II
//
//  Created by Colin on 23/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxProfit(vector<int>& prices) {
    int priceCount = prices.size();
    if(priceCount < 2) return 0;
    int totalProfit = 0;
    for(int i = 1; i < priceCount; ++i) {
        int currDiff = prices[i] - prices[i - 1];
        if(currDiff > 0) totalProfit += currDiff;
    }
    return totalProfit;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
