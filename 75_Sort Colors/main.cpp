//
//  main.cpp
//  75_Sort Colors
//
//  Created by Colin on 24/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void sortColors(vector<int>& nums) {
    int numCount = nums.size();
    int zero = -1, two = numCount;
    for(int i = 0; i < numCount; ++i) {
        while(i < two && i > zero && nums[i] != 1) {
            while(nums[i] == 0 && i > zero) swap(nums[i], nums[++zero]);
            while(nums[i] == 2 && i < two) swap(nums[i], nums[--two]);
        }
    }
    return ;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
