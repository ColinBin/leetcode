//
//  main.cpp
//  199_Binary Tree Right Side View
//
//  Created by Colin on 16/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"
#include <vector>

using namespace std;

void dfs(vector<int> &res, int level, TreeNode *current) {
    if(current == nullptr)
        return;
    if(level == res.size()) {
        res.push_back(current->val);
    } else {
        res[level] = current->val;
    }
    dfs(res, level + 1, current->left);
    dfs(res, level + 1, current->right);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    dfs(res, 0, root);
    return res;
}



int main(int argc, const char * argv[]) {
    
    return 0;
}
