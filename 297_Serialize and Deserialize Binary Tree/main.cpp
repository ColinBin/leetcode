//
//  main.cpp
//  297_Serialize and Deserialize Binary Tree
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class Codec {
public:
    
    string bfs(TreeNode *root) {
        if(root == nullptr)
            return "";
        queue<TreeNode *> q;
        q.push(root);
        string result = to_string(root->val);
        while(!q.empty()) {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; ++i) {
                TreeNode *current = q.front();
                q.pop();
                if(current == nullptr)
                    continue;
                appendChild(result, current->left);
                appendChild(result, current->right);
                q.push(current->left);
                q.push(current->right);
            }
        }
        return result;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return bfs(root);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return nullptr;
        istringstream iss(data);
        string rootStr;
        iss >> rootStr;
        TreeNode *root = new TreeNode(stoi(rootStr.c_str()));
        queue<TreeNode *> q;
        q.push(root);
        while(!iss.eof()) {
            int levelSize = q.size();
            for(int i = 0; i < levelSize; ++i) {
                TreeNode *current = q.front();
                q.pop();
                string left, right;
                iss >> left >> right;
                if(left != "null") {
                    TreeNode *leftChild = new TreeNode(stoi(left.c_str()));
                    current->left = leftChild;
                    q.push(leftChild);
                } else {
                    current->left = nullptr;
                }
                if(right != "null") {
                    TreeNode *rightChild = new TreeNode(stoi(right.c_str()));
                    current->right = rightChild;
                    q.push(rightChild);
                } else {
                    current->right = nullptr;
                }
            }
        }
        return root;
    }
private:
    void appendChild(string &result, TreeNode *current) {
        if(current != nullptr) {
            result += " " + to_string(current->val);
        } else {
            result += " null";
        }
    }
};

int main(int argc, const char * argv[]) {
    string tree = "1 2 3 null null 4 5 null 6 null null null null";
    Codec codec;
    cout << codec.serialize(codec.deserialize(tree)) << endl;
    return 0;
}
