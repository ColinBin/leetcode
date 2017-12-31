//
//  main.cpp
//  404_Sum of Left Leaves
//
//  Created by Colin on 30/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int helper(TreeNode *current, bool isLeft) {
    if(current == nullptr) return 0;
    if(current->left == nullptr && current->right == nullptr) {
        if(isLeft)
            return current->val;
        else
            return 0;
    }
    int leftSubTreeSum = helper(current->left, true);
    int rightSubTreeSum = helper(current->right, false);
    return leftSubTreeSum + rightSubTreeSum;
}

int sumOfLeftLeaves(TreeNode* root) {
    if(root == nullptr)
        return 0;
    //    return helper(root, false);
    queue<TreeNode *> q;
    int result = 0;
    q.push(root);
    while(!q.empty()) {
        TreeNode *current = q.front();
        q.pop();
        if(current->left != nullptr) {
            if(current->left->left == nullptr && current->left->right == nullptr)
                result += current->left->val;
            else
                q.push(current->left);
        }
        if(current->right != nullptr) {
            q.push(current->right);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
