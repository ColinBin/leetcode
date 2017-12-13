//
//  main.cpp
//  218_The Skyline Problem
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights temperved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct compareRight {
    bool operator()(const pair<int, int> b1, const pair<int, int> b2) {
        return b1.second > b2.second;
    }
};
struct compareHeight {
    bool operator()(const pair<int, int> b1, const pair<int, int> b2) {
        return b1.second < b2.second;
    }
};

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    
    vector<pair<int, int>> temp;
    if(buildings.size() == 0) {
        return temp;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareRight> rightMinHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareHeight> heightMaxHeap;
    set<int> done;
    vector<int> dummy = {INT_MAX, INT_MAX, 0};
    buildings.push_back(dummy);
    int buildingCount = buildings.size();
    for(int i = 0; i < buildingCount; ++i) {
        int left = buildings[i][0];
        int right = buildings[i][1];
        int height = buildings[i][2];
        int lastRight = -1;
        while(!rightMinHeap.empty() && rightMinHeap.top().second < left) {
            done.insert(rightMinHeap.top().first);
            int currentRight = rightMinHeap.top().second;
            rightMinHeap.pop();
            while(!heightMaxHeap.empty() && done.find(heightMaxHeap.top().first) != done.end())
                heightMaxHeap.pop();
            if(currentRight == lastRight && !heightMaxHeap.empty())
                continue;
            lastRight = currentRight;
            int currentHeight = heightMaxHeap.empty() ? 0 : heightMaxHeap.top().second;
            temp.push_back(make_pair(currentRight, currentHeight));
        }
        
        heightMaxHeap.push(make_pair(i, height));
        rightMinHeap.push(make_pair(i, right));
        
        while(i + 1 < buildingCount && buildings[i + 1][0] == left) {
            ++i;
            heightMaxHeap.push(make_pair(i, buildings[i][2]));
            rightMinHeap.push(make_pair(i, buildings[i][1]));
        }
       
        temp.push_back(make_pair(left, heightMaxHeap.top().second));
    }
    vector<pair<int, int>> res;
    int currentHeight = -1;
    for(auto ele : temp) {
        if(ele.second != currentHeight) {
            res.push_back(ele);
            currentHeight = ele.second;
        }
    }
    if(buildings[buildingCount - 2][1] == INT_MAX) {
        res.push_back(make_pair(INT_MAX, 0));
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> buildings = {{0,2147483647,2147483647}};
    auto res = getSkyline(buildings);
    for(auto ele : res) {
        cout << ele.first << " " << ele.second << endl;
    }
    return 0;
}
