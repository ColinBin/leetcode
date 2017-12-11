//
//  main.cpp
//  215_Kth Largest Element in an Array
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compareEle {
    bool operator()(const int first, const int second) {
        return first > second;
    }
};

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, compareEle> minHeap(nums.begin(), nums.begin() + k);
    for(int i = k; i < nums.size(); ++i) {
        if(nums[i] > minHeap.top()) {
            minHeap.pop();
            minHeap.push(nums[i]);
        }
    }
    return minHeap.top();
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,2,1,5,6,4};
    cout << findKthLargest(nums, 3) << endl;
    return 0;
}
