//
//  main.cpp
//  530_Minimum Absolute Difference in BST
//
//  Created by Colin on 06/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

TreeNode *prev = nullptr;
int minDiff = INT_MAX;

int getMinimumDifference(TreeNode* root) {
    if(root == nullptr) return 0;
    getMinimumDifference(root->left);
    if(prev != nullptr) {
        minDiff = min(minDiff, root->val - prev->val);
    }
    prev = root;
    getMinimumDifference(root->right);
    return minDiff;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
