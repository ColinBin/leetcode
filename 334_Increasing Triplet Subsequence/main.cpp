//
//  main.cpp
//  334_Increasing Triplet Subsequence
//
//  Created by Colin on 20/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int end1 = INT_MAX, end2 = INT_MAX;
    for(const int num : nums) {
        if(num < end1) {
            end1 = num;
        } else if(num < end2 && num > end1){
            end2 = num;
        } else if(num > end2) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
