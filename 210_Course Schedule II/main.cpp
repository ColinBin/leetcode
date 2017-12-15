//
//  main.cpp
//  210_Course Schedule II
//
//  Created by Colin on 15/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool dfsCycle(vector<int> &result, vector<set<int>> &children, vector<bool> &onpath, vector<bool> &visited, int i) {
    if(visited[i]) return false;
    onpath[i] = true;
    for(int child : children[i]) {
        if(onpath[child] || dfsCycle(result, children, onpath, visited, child))
            return true;
    }
    visited[i] = true;
    result.push_back(i);
    onpath[i] = false;
    return false;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> result;
    vector<set<int>> children(numCourses);
    for(const auto &ele : prerequisites) {
        children[ele.second].insert(ele.first);
    }
    vector<bool> onpath(numCourses, false);
    vector<bool> visited(numCourses, false);
    for(int i = 0; i < numCourses; ++i) {
        if(!visited[i]) {
            if(dfsCycle(result, children, onpath, visited, i)) {
                return vector<int> ();
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
