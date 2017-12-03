//
//  main.cpp
//  84_Largest_Rectangle_in_Histogram
//
//  Created by Colin on 23/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    
    heights.push_back(0);
    int heightCount = heights.size();
    stack<int> stk;
    stk.push(0);
    int dummy = 1, maxArea = 0;
    while(dummy < heightCount) {
        int currHeight = heights[dummy];
        if(currHeight > heights[stk.top()]) {
            stk.push(dummy);
        } else {
            int topHeight;
            while(!stk.empty() && (topHeight = heights[stk.top()]) > currHeight) {
                stk.pop();
                maxArea = max(maxArea, topHeight * (stk.empty() ? dummy : (dummy - stk.top() - 1)));
            }
            stk.push(dummy);
        }
        ++dummy;
    }
    return maxArea;
}

int main(int argc, const char * argv[]) {
    vector<int> heights = {6,5,4,3,2,1};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
