//
//  main.cpp
//  239_Sliding Window Maximum
//
//  Created by Colin on 21/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int numCount = nums.size();
    if(numCount == 0)
        return res;
    deque<int> dq;
    for(int i = 0; i < numCount; ++i) {
        if(!dq.empty() && dq.front() < i - k + 1)
            dq.pop_front();
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if(i >= k - 1) {
            res.push_back(nums[dq.front()]);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, -1};
    int k = 1;
    auto res = maxSlidingWindow(nums, k);
    for(const auto ele : res) {
        cout << ele << endl;
    }
    return 0;
}
