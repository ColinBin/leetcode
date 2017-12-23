//
//  main.cpp
//  617_Merge Two Binary Trees
//
//  Created by Colin on 22/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1 == nullptr)
        return t2;
    if(t2 == nullptr)
        return t1;
    stack<pair<TreeNode *, TreeNode *>> stk;
    stk.push(make_pair(t1, t2));
    while(!stk.empty()) {
        auto pr = stk.top();
        stk.pop();
        TreeNode *first = pr.first, *second = pr.second;
        first->val += second->val;
        if(first->left != nullptr && second->left != nullptr) {
            stk.push(make_pair(first->left, second->left));
        } else if(first->left == nullptr) {
            first->left = second->left;
        }
        if(first->right != nullptr && second->right != nullptr) {
            stk.push(make_pair(first->right, second->right));
        } else if(first->right == nullptr) {
            first->right = second->right;
        }
    }
    return t1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
