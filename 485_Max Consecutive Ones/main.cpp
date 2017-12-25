//
//  main.cpp
//  485_Max Consecutive Ones
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0, current = 0;
    nums.push_back(0);
    for(const int num : nums) {
        if(num != 0) {
            ++current;
        } else {
            res = max(res, current);
            current = 0;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
