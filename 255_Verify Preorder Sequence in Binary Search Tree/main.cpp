//
//  main.cpp
//  255_Verify Preorder Sequence in Binary Search Tree
//
//  Created by Colin on 19/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool verifyPreorder(vector<int>& preorder) {
    stack<int> stk;
    int low = INT_MIN;
    for(const int ele : preorder) {
        if(ele < low)
            return false;
        while(!stk.empty() && stk.top() < ele) {
            low = stk.top();
            stk.pop();
        }
        stk.push(ele);
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
