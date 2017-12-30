//
//  main.cpp
//  270_Closest Binary Search Tree Value
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int closestValue(TreeNode* root, double target) {
    if(root->val == target)
        return root->val;
    int closest = root->val;
    if(root->val > target && root->left != nullptr) {
        int childClosest = closestValue(root->left, target);
        if(abs(target - closest) > abs(childClosest - target))
            closest = childClosest;
    }
    if(root->val < target && root->right != nullptr) {
        int childClosest = closestValue(root->right, target);
        if(abs(childClosest - target) < abs(closest - target))
            closest = childClosest;
    }
    return closest;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
