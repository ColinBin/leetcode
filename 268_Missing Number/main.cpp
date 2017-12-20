//
//  main.cpp
//  268_Missing Number
//
//  Created by Colin on 19/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) {
    int numCount = nums.size();
    int res = 0;
    for(int i = 0; i < numCount; ++i) {
        res = res ^ i ^nums[i];
    }
    return res ^ numCount;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
