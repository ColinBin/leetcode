//
//  main.cpp
//  538_Convert BST to Greater Tree
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

TreeNode* convertBST(TreeNode* root) {
    stack<TreeNode *> stk;
    TreeNode *dummy = root;
    int currentSum = 0;
    while(!stk.empty() || dummy != nullptr) {
        while(dummy != nullptr) {
            stk.push(dummy);
            dummy = dummy->right;
        }
        
        dummy = stk.top();
        stk.pop();
        currentSum += dummy->val;
        dummy->val = currentSum;
        
        dummy = dummy->left;
    }
    return root;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
