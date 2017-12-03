//
//  main.cpp
//  518_coin_change_2
//
//  Created by Colin on 09/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for(int coin : coins) {
        for(int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    return dp[amount];
}

int main(int argc, const char * argv[]) {
    int amount = 5;
    vector<int> coins = {1,2,5};
    cout << change(amount, coins) << endl;
    return 0;
}
