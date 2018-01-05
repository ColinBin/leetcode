//
//  main.cpp
//  480_Sliding Window Median
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> res;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> discarded;
    int numCount = nums.size();
    for(int i = 0; i < k; ++i)
        maxHeap.push(nums[i]);
    for(int i = 0; i < k / 2; ++i) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    bool isOdd = k % 2;
    if(isOdd) res.push_back(maxHeap.top());
    else res.push_back(0.5 * maxHeap.top() + minHeap.top() * 0.5);
    
    for(int i = k; i < numCount; ++i) {
        int toDiscard = nums[i - k], toAdd = nums[i];
        ++discarded[toDiscard];
        if(toDiscard <= maxHeap.top()) {
            if(minHeap.empty() || toAdd <= minHeap.top())
                maxHeap.push(toAdd);
            else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(toAdd);
            }
        } else {
            if(toAdd >= maxHeap.top())
                minHeap.push(toAdd);
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(toAdd);
            }
        }
        while(!maxHeap.empty() && discarded[maxHeap.top()] > 0) {
            --discarded[maxHeap.top()];
            maxHeap.pop();
        }
        while(!minHeap.empty() && discarded[minHeap.top()] > 0) {
            --discarded[minHeap.top()];
            minHeap.pop();
        }
        if(isOdd) res.push_back(maxHeap.top());
        else res.push_back(0.5 * maxHeap.top() + minHeap.top() * 0.5);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
