//
//  main.cpp
//  323_Number of Connected Components in an Undirected Graph
//
//  Created by Colin on 13/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int findRoot(int i, vector<int> &parent) {
    while(parent[i] != i) {
        i = parent[i];
    }
    return i;
}

int countComponents(int n, vector<pair<int, int>>& edges) {
    if(n < 2) {
        return n;
    }
    vector<int> parent(n, 0);
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for(const auto edge : edges) {
        int root1 = findRoot(edge.first, parent);
        int root2 = findRoot(edge.second, parent);
        if(root1 != root2) {
            parent[root2] = root1;
            --n;
        }
    }
    return n;
}


int main(int argc, const char * argv[]) {
    
    return 0;
}
