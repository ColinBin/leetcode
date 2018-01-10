//
//  main.cpp
//  11_Container With Most Water
//
//  Created by Colin on 09/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxArea(vector<int>& height) {
    int heightCount = height.size();
    int left = 0, right = heightCount - 1;
    int res = 0;
    while(left < right) {
        int leftHeight = height[left], rightHeight = height[right];
        res = max(res, (right - left) * min(leftHeight, rightHeight));
        if(leftHeight <= rightHeight) {
            while(left < right && height[left] <= leftHeight) ++left;
        } else {
            while(left < right && height[right] <= rightHeight) -- right;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {

    return 0;
}
