//
//  main.cpp
//  207_Course Schedule
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool dfsCycle(vector<set<int>> &children, vector<bool> &onpath, vector<bool> &visited, int i) {
    if(visited[i]) return false;
    onpath[i] = visited[i] = true;
    for(int child : children[i]) {
        if(onpath[child])
            return true;
        if(dfsCycle(children, onpath, visited, child))
            return true;
    }
    onpath[i] = false;
    return false;
}

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<set<int>> children(numCourses);
    for(const auto ele : prerequisites) {
        children[ele.first].insert(ele.second);
    }
    vector<bool> onpath(numCourses, false);
    vector<bool> visited(numCourses, false);
    for(int i = 0; i < numCourses; ++i) {
        if(!visited[i]){
            if(dfsCycle(children, onpath, visited, i))
                return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
