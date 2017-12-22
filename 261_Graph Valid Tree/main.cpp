//
//  main.cpp
//  261_Graph Valid Tree
//
//  Created by Colin on 21/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "basic_ds.hpp"

using namespace std;

int findRoot(vector<int> &parent, int index) {
    while(index != parent[index]) {
        index = parent[index];
    }
    return index;
}

bool validTreeUnion(int n, vector<pair<int, int>>& edges) {
    vector<int> parent(n);
    int edgeCount = edges.size();
    if(edgeCount != n - 1)
        return false;
    for(int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    for(const auto edge : edges){
        int root1 = findRoot(parent, edge.first), root2 = findRoot(parent, edge.second);
        if(root1 == root2)
            return false;
        parent[root1] = root2;
    }
    return true;
}

bool dfsCycle(const vector<vector<int>> &graph, const int parent, const int current, set<int> &visited) {
    visited.insert(current);
    for(const int child : graph[current]) {
        if(child != parent && visited.find(child) != visited.end()) {
            return true;
        }
        if(child == parent)
            continue;
        if(dfsCycle(graph, current, child, visited))
            return true;
    }
    return false;
}

bool validTree(int n, vector<pair<int, int>>& edges) {
    // return validTreeUnion(n, edges);
    vector<vector<int>> graph(n);
    int edgeCount = edges.size();
    if(edgeCount != n - 1)
        return false;
    for(const auto &edge : edges) {
        graph[edge.first].push_back(edge.second);
        graph[edge.second].push_back(edge.first);
    }
    set<int> visited;
    bool isCycle = dfsCycle(graph, -1, 0, visited);
    return visited.size() == n && !isCycle;
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> edges = {{0,1},{2,3},{1,2}};
    cout << validTree(4, edges) << endl;
    return 0;
}
