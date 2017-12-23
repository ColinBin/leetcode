//
//  main.cpp
//  561_Array Partition I
//
//  Created by Colin on 22/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for(int i = 0; i < nums.size(); i += 2) {
        sum += nums[i];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    /
    return 0;
}
