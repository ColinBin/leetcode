//
//  main.cpp
//  536_Construct Binary Tree from String
//
//  Created by Colin on 06/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

TreeNode *helper(const string &s, int &iter) {
    if(s[iter] == ')') return nullptr;
    bool isNegative = false;
    if(s[iter] == '-') {
        isNegative = true;
        ++iter;
    }
    int val = 0;
    while(iter < s.length() && s[iter] >= '0' && s[iter] <= '9') {
        val = val * 10 + s[iter] - '0';
        ++iter;
    }
    val = isNegative ? -val : val;
    TreeNode *current = new TreeNode(val);
    if(iter < s.length() && s[iter] == '(') {
        ++iter;
        current->left = helper(s, iter);
        ++iter;
        if(s[iter] == '(') {
            ++iter;
            current->right = helper(s, iter);
            ++iter;
        }
    }
    return current;
 }

TreeNode* str2tree(string s) {
//    int sLen = s.length();
//    if(sLen == 0) return nullptr;
//    int iter = 0;
//    return helper(s, iter);
    int sLen = s.length();
    if(sLen == 0) return nullptr;
    int iter = 0;
    unordered_set<TreeNode *> done;
    stack<TreeNode *> stk;
    s += ")";
    while(iter <= sLen) {
        if(s[iter] == ')') {
            if(done.find(stk.top()) == done.end()) {
                done.insert(stk.top());
            } else {
                TreeNode *first = stk.top();
                stk.pop();
                if(done.find(stk.top()) == done.end()) {
                    done.insert(stk.top());
                    stk.top()->left = first;
                } else {
                    TreeNode *second = stk.top();
                    stk.pop();
                    done.insert(stk.top());
                    stk.top()->left = second;
                    stk.top()->right = first;
                }
            }
            ++iter;
        } else if(s[iter] == '(') {
            ++iter;
        } else {
            bool isNegative = false;
            if(s[iter] == '-') {
                isNegative = true;
                ++iter;
            }
            int val = 0;
            while(iter < sLen && s[iter] >= '0' && s[iter] <= '9') {
                val = val * 10 + s[iter] - '0';
                ++iter;
            }
            if(isNegative) val = -val;
            TreeNode *current = new TreeNode(val);
            stk.push(current);
        }
    }
    return stk.top();
}

int main(int argc, const char * argv[]) {
    str2tree("4(2(3)(1))(6(5))");
    return 0;
}
