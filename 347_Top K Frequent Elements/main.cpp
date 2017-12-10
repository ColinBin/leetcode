//
//  main.cpp
//  347_Top K Frequent Elements
//
//  Created by Colin on 09/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

struct bigger{
    bool operator()(pair<int, int> &one, pair<int, int>two){
        return one.second > two.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> records;
    for(const int num : nums) {
        ++records[num];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, bigger> heap;
    int i = 0;
    for(auto record : records) {
        heap.push(record);
        if(i >= k) {
            heap.pop();
        }
        ++i;
    }
    for(int i = 0; i < k; ++i) {
        res.push_back(heap.top().first);
        heap.pop();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,1,2,2,3};
    auto res = topKFrequent(nums, 2);
    for(auto ele : res)  {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
