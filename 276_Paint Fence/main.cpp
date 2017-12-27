//
//  main.cpp
//  276_Paint Fence
//
//  Created by Colin on 26/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int numWays(int n, int k) {
    if(k == 0 || n == 0)
        return 0;
    if(n == 1)
        return k;
    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = k;
    for(int i = 2; i < n; ++i) {
        dp[i] = (k - 1) * (dp[i - 1] + dp[i - 2]);
    }
    return dp[n - 1] * k;
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
