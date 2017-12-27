//
//  main.cpp
//  314_Binary Tree Vertical Order Traversal
//
//  Created by Colin on 26/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(root == nullptr) return result;
    unordered_map<int, vector<int>> record;
    queue<pair<TreeNode *, int>> q;
    int minIndex = 0, maxIndex = 0;
    q.push({root, 0});
    while(!q.empty()) {
        TreeNode *currentNode = q.front().first;
        int currentIndex = q.front().second;
        q.pop();
        record[currentIndex].push_back(currentNode->val);
        minIndex = min(minIndex, currentIndex);
        maxIndex = max(maxIndex, currentIndex);
        if(currentNode->left != nullptr)
            q.push({currentNode->left, currentIndex - 1});
        if(currentNode->right != nullptr)
            q.push({currentNode->right, currentIndex + 1});
    }
    for(int i = minIndex; i < maxIndex; ++i){
        result.push_back(record[i]);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    deque<int> dq = {3,4,5};
    cout << dq[1] << endl;
    dq.push_front(7);
    cout << dq[1] << endl;
    return 0;
}
