//
//  main.cpp
//  606_Construct String from Binary Tree
//
//  Created by Colin on 06/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void preorder(TreeNode *current, string &res) {
    res += to_string(current->val);
    if(current->left != nullptr) {
        res += "(";
        preorder(current->left, res);
        res += ")";
        if(current->right != nullptr) {
            res += "(";
            preorder(current->right, res);
            res += ")";
        }
    } else if(current->right != nullptr) {
        res += "()(";
        preorder(current->right, res);
        res += ")";
    }
    return;
}

string tree2str(TreeNode* t) {
//    string res = "";
//    if(t == nullptr) return res;
//    preorder(t, res);
//    return res;
    if(t == nullptr) return "";
    unordered_set<TreeNode *> record;
    stack<TreeNode *> stk;
    string res;
    stk.push(t);
    while(!stk.empty()) {
        TreeNode *current = stk.top();
        if(record.find(current) != record.end()) {
            res += ")";
            stk.pop();
        } else {
            res += "(";
            res += to_string(current->val);
            if(current->right != nullptr) {
                stk.push(current->right);
                if(current->left != nullptr) {
                    stk.push(current->left);
                } else {
                    res += "()";
                }
            } else {
                if(current->left != nullptr) {
                    stk.push(current->left);
                }
            }
            record.insert(current);
        }
    }
    return res.substr(1, res.length() - 2);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
