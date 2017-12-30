//
//  main.cpp
//  272_Closest Binary Search Tree Value II
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<int> closestKValues(TreeNode* root, double target, int k) {
    stack<TreeNode *> stk;
    TreeNode *dummy = root;
    deque<int> window;
    while(!stk.empty() || dummy != nullptr) {
        while(dummy != nullptr) {
            stk.push(dummy);
            dummy = dummy->left;
        }
        dummy = stk.top();
        stk.pop();
        if(window.size() < k)
            window.push_back(dummy->val);
        else {
            if(abs(window.front() - target) > abs(dummy->val - target)) {
                window.pop_front();
                window.push_back(dummy->val);
            } else {
                break;
            }
        }
        if(dummy->right != nullptr) {
            dummy = dummy->right;
        }
    }
    return vector<int> (window.begin(), window.end());
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
