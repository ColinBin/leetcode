//
//  main.cpp
//  310_Minimum Height Trees
//
//  Created by Colin on 04/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;
// any node that has already been a leaf cannot be the root of a MHT, because its adjacent non-leaf node will always be a better candidate
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
    vector<int> res;
    if(n == 0)
        return res;
    else if(n == 1) {
        res.push_back(0);
        return res;
    }
    vector<vector<int>> neighbours(n, vector<int> ());
    vector<int> degree(n, 0);
    for(const auto &edge : edges) {
        neighbours[edge.first].push_back(edge.second);
        neighbours[edge.second].push_back(edge.first);
        ++degree[edge.first];
        ++degree[edge.second];
    }
    vector<int> q;
    for(int i = 0; i < n; ++i) {
        if(degree[i] == 1)
            q.push_back(i);
    }
    while(!q.empty()) {
        vector<int> next;
        for(const int current : q) {
            for(const int neighbour : neighbours[current]) {
                if(--degree[neighbour] == 1)
                    next.push_back(neighbour);
            }
        }
        if(next.empty()) {
            res = q;
            break;
        }
        q = next;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
