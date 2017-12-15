//
//  main.cpp
//  133_Clone Graph
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include "../basic_ds.hpp"

using namespace std;

UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> &found) {
    if(node == nullptr)
        return nullptr;
    if(found.find(node) == found.end()) {
        found[node] = new UndirectedGraphNode(node->label);
        for(UndirectedGraphNode * neighbour : node->neighbors) {
            found[node]->neighbors.push_back(cloneGraphHelper(neighbour, found));
        }
    }
    return found[node];
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> found;
    return cloneGraphHelper(node, found);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
