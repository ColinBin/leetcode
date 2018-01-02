//
//  main.cpp
//  637_Average of Levels in Binary Tree
//
//  Created by Colin on 31/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    queue<TreeNode *> q;
    if(root == nullptr) return res;
    q.push(root);
    while(!q.empty()) {
        int levelCount = q.size();
        int sum = 0;
        for(int i = 0; i < levelCount; ++i) {
            TreeNode *current = q.front();
            q.pop();
            sum += current->val;
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
        }
        res.push_back(sum * 1.0 / levelCount);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
