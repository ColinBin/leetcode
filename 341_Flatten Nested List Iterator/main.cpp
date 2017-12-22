//
//  main.cpp
//  341_Flatten Nested List Iterator
//
//  Created by Colin on 19/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <stack>
#include "../basic_ds.hpp"

using namespace std;

class NestedIterator {
public:
    using iterator = vector<const NestedInteger>::iterator;
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push(make_pair(nestedList.begin(), nestedList.end()));
    }
    
    int next() {
        int val = stk.top().first->getInteger();
        ++stk.top().first;
        return val;
    }
    
    bool hasNext() {
        while(!stk.empty()) {
            iterator iter = stk.top().first, end = stk.top().second;
            if(iter == end)
                stk.pop();
            else {
                if(iter->isInteger()) {
                    return true;
                } else {
                    // special attention!
                    const vector<NestedInteger> &newChildList = iter->getList();
                    ++(stk.top().first);
                    stk.push(make_pair(newChildList.begin(), newChildList.end()));
                }
            }
        }
        return false;
    }
private:
    stack<pair<iterator, iterator>> stk;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
