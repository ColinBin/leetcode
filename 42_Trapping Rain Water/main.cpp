//
//  main.cpp
//  42_Trapping Rain Water
//
//  Created by Colin on 09/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int trap(vector<int>& height) {
    int heightCount = height.size();
    int left = 0, right = heightCount - 1;
    int total = 0;
    while(left < right) {
        int leftHeight = height[left], rightHeight = height[right];
        if(leftHeight <= rightHeight) {
            while(left < right && height[left] <= leftHeight) {
                total += leftHeight - height[left];
                ++left;
            }
        } else {
            while(left < right && height[right] <= rightHeight) {
                total += rightHeight - height[right];
                --right;
            }
        }
    }
    return total;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
