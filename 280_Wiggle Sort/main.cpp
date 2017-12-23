//
//  main.cpp
//  280_Wiggle Sort
//
//  Created by Colin on 22/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void wiggleSort(vector<int>& nums) {
    int numCount = nums.size();
    for(int i = 1; i < numCount; i += 2) {
        if(i + 1 < numCount) {
            int sum = nums[i - 1] + nums[i] + nums[i + 1];
            int max = max(nums[i - 1], max(nums[i], nums[i + 1]));
            int min = min(nums[i - 1], min(nums[i], nums[i + 1]));
            nums[i - 1] = min;
            nums[i] = max;
            nums[i + 1] = sum - max - min;
        } else {
            int max = max(nums[i], nums[i - 1]);
            int min = min(nums[i], nums[i - 1]);
            nums[i - 1] = min;
            nums[i] = max;
        }
    }
    return ;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
