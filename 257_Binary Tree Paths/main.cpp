//
//  main.cpp
//  257_Binary Tree Paths
//
//  Created by Colin on 15/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "../basic_ds.hpp"

using namespace std;

void addNewPath(vector<int> &tempList, vector<string> &res) {
    string current = to_string(tempList[0]);
    for(int i = 1; i < tempList.size(); ++i) {
        current += ("->" + to_string(tempList[i]));
    }
    res.push_back(current);
}

void dfs(vector<string> &res, vector<int> &tempList, TreeNode *current) {
    tempList.push_back(current->val);
    if(current->left == nullptr && current->right == nullptr) {
        addNewPath(tempList, res);
    } else {
        if(current->left != nullptr) {
            dfs(res, tempList, current->left);
        }
        if(current->right != nullptr) {
            dfs(res, tempList, current->right);
        }
    }
    tempList.pop_back();
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if(root == nullptr)
        return res;
    vector<int> tempList;
    dfs(res, tempList, root);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
