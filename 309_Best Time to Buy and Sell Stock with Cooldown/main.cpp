//
//  main.cpp
//  309_Best Time to Buy and Sell Stock with Cooldown
//
//  Created by Colin on 27/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxProfit(vector<int>& prices) {
    int priceCount = prices.size();
    if(priceCount < 2)
        return 0;
    int pbuy = INT_MIN, psell = 0, ppsell = 0, buy = 0, sell = 0;
    for(const int price : prices) {
        buy = max(pbuy, ppsell - price);
        sell = max(psell, pbuy + price);
        ppsell = psell;
        psell = sell;
        pbuy = buy;
    }
    return sell;
}

int main(int argc, const char * argv[]) {
    vector<int> prices = {1,2,4};
    cout << maxProfit(prices) << endl;
    return 0;
}
