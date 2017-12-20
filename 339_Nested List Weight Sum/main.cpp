//
//  main.cpp
//  339_Nested List Weight Sum
//
//  Created by Colin on 19/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include "../basic_ds.hpp"
using namespace std;

int depthSumHelper(vector<NestedInteger> &nestedList, int depth) {
    int sum = 0;
    for(NestedInteger &current : nestedList) {
        if(current.isInteger())
            sum += current.getInteger() * depth;
        else
            sum += depthSumHelper(current.getList(), depth + 1);
    }
    return sum;
}

int depthSum(vector<NestedInteger>& nestedList) {
    return depthSumHelper(nestedList, 1);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
