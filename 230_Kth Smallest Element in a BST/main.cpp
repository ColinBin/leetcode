//
//  main.cpp
//  230_Kth Smallest Element in a BST
//
//  Created by Colin on 13/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    TreeNode *dummy = root;
    while(dummy != nullptr) {
        if(dummy->left == nullptr) {
            ++count;
            if(count == k)
                result = dummy->val;
            dummy = dummy->right;
        } else {
            TreeNode *candidate = dummy->left;
            while(candidate->right != dummy && candidate->right != nullptr)
                candidate = candidate->right;
            if(candidate->right == nullptr) {
                candidate->right = dummy;
                dummy = dummy->left;
            } else {
                candidate->right = nullptr;
                ++count;
                if(count == k)
                    result = dummy->val;
                dummy = dummy->right;
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
