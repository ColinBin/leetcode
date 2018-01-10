//
//  main.cpp
//  287_Find the Duplicate Number
//
//  Created by Colin on 09/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int findDuplicate(vector<int>& nums) {
    int numCount = nums.size();
    int fast = 0, slow = 0;
    while(true) {
        fast = nums[nums[fast]];
        slow = nums[slow];
        if(fast == slow) {
            fast = 0;
            while(fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
