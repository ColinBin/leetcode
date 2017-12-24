//
//  main.cpp
//  628_Maximum Product of Three Numbers
//
//  Created by Colin on 23/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maximumProduct(vector<int>& nums) {
    int max1 = INT_MIN, max2  = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;
    for(const int num : nums) {
        if(num >= max1) {
            swap(max2, max3);
            swap(max1, max2);
            max1 = num;
        } else if(num >= max2) {
            swap(max2, max3);
            max2 = num;
        } else if(num > max3) {
            max3 = num;
        }
        if(num <= min1) {
            swap(min1, min2);
            min1 = num;
        } else if(num < min2) {
            min2 = num;
        }
    }
    return max(max1 * max2 * max3, min1 * min2 * max1);
    
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
