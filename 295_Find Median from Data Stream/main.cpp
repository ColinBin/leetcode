//
//  main.cpp
//  295_Find Median from Data Stream
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class compareEle {
    bool operator()(const int val1, const int val2) {
        return val1 > val2;
    }
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()) {
            maxHeap.push(num);
        } else if(isEven) {
            if(num <= minHeap.top())
                maxHeap.push(num);
            else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
        } else {
            if(num >= maxHeap.top())
                minHeap.push(num);
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        isEven = !isEven;
    }
    
    double findMedian() {
        if(isEven) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
private:
    bool isEven = true;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, compareEle> minHeap;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
