//
//  main.cpp
//  391_Perfect Rectangle
//
//  Created by Colin on 24/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void removeOrInsert(set<pair<int, int>> &points, pair<int, int> target) {
    if(points.find(target) == points.end()) {
        points.insert(target);
    } else {
        points.erase(target);
    }
}

bool isRectangleCover(vector<vector<int>>& rectangles) {
    int rowCount = rectangles.size();
    if(rowCount == 0)
        return false;
    int colCount = rectangles[0].size();
    set<pair<int, int>> points;
    int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN;
    int totalArea = 0;
    for(const auto &row : rectangles) {
        totalArea += (row[2] - row[0]) * (row[3] - row[1]);
        x1 = min(x1, row[0]);
        y1 = min(y1, row[1]);
        x2 = max(x2, row[2]);
        y2 = max(y2, row[3]);
        
        removeOrInsert(points, {row[0], row[1]});
        removeOrInsert(points, {row[0], row[3]});
        removeOrInsert(points, {row[2], row[1]});
        removeOrInsert(points, {row[2], row[3]});
    }
    if(points.find(make_pair(x1, y1)) == points.end() ||
       points.find(make_pair(x1, y2)) == points.end() ||
       points.find(make_pair(x2, y1)) == points.end() ||
       points.find(make_pair(x2, y2)) == points.end())
        return false;
    return totalArea == (y2 - y1) * (x2 - x1) && points.size() == 4;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
