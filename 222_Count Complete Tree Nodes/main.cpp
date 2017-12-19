//
//  main.cpp
//  222_Count Complete Tree Nodes
//
//  Created by Colin on 18/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int countNodesHelper(TreeNode *root, int level) {
    if(root == nullptr || level == 0)
        return 0;
    if(root->left == nullptr && root->right == nullptr || level == 1)
        return 1;
    TreeNode *iter = root->left;
    int leftLevel = 0;
    while(iter != nullptr) {
        iter = iter->right;
        ++leftLevel;
    }
    int totalCount = 0;
    // left sub tree is full
    if(leftLevel == level - 1) {
        totalCount = (1 << (level - 1)) + countNodesHelper(root->right, level - 1);
    } else {
        // left sub tree is not full
        totalCount = (1 << (level - 2)) + countNodesHelper(root->left, level - 1);
    }
    return totalCount;
}

int countNodes(TreeNode* root) {
    int level = 0;
    TreeNode *iter = root;
    while(iter != nullptr) {
        ++level;
        iter = iter->left;
    }
    return countNodesHelper(root, level);
}

int main(int argc, const char * argv[]) {
    cout << (2 << -1) << endl;
    return 0;
}
