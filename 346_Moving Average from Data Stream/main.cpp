//
//  main.cpp
//  346_Moving Average from Data Stream
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        sz = size;
    }
    
    double next(int val) {
        buffer.push(val);
        currentSum += val;
        if(buffer.size() <= sz)
            return currentSum / buffer.size();
        currentSum -= buffer.front();
        buffer.pop();
        return currentSum / sz;
    }
private:
    int sz;
    double currentSum = 0;
    queue<int> buffer;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
