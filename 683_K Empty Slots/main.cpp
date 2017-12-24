//
//  main.cpp
//  683_K Empty Slots
//
//  Created by Colin on 23/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int kEmptySlots(vector<int>& flowers, int k) {
    int flowerCount = flowers.size();
    if(k < 0 || k > flowerCount - 2 || flowerCount == 0)
        return -1;
    unordered_map<int, int> forecast;
    for(int i = 0; i < flowerCount; ++i) {
        forecast[flowers[i] - 1] = i + 1;
    }
    deque<int> record;
    int result = INT_MAX;
    for(int i = 1; i < flowerCount - 1; ++i) {
        int currentDay = forecast[i];
        if(!record.empty() && i - record.front() + 1 > k)
            record.pop_front();
        while(!record.empty() && forecast[record.back()] > currentDay){
            record.pop_back();
        }
        record.push_back(i);
        if(i >= k) {
            int minStart = forecast[record.front()];
            int leftStart = forecast[i - k];
            int rightStart = forecast[i + 1];
            if(k == 0 || leftStart < minStart && rightStart < minStart) {
                result = min(result, max(leftStart, rightStart));
            }
        }
    }
    return result == INT_MAX ? -1 : result;
}

int main(int argc, const char * argv[]) {
    vector<int> flowers = {3,9,2,8,1,6,10,5,4,7};
    cout << kEmptySlots(flowers, 0) << endl;
    return 0;
}
