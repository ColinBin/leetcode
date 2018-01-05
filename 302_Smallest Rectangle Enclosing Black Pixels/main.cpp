//
//  main.cpp
//  302_Smallest Rectangle Enclosing Black Pixels
//
//  Created by Colin on 04/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int findColumn(const vector<vector<char>> &image, int left, int right, bool has) {
    while(left < right) {
        int mid = left + (right - left) / 2;
        bool found = false;
        for(const auto &row : image) {
            if(row[mid] == '1') {
                found = true;
                break;
            }
        }
        if(found)  {
            if(has)
                right = mid;
            else
                left = mid + 1;
        } else {
            if(has)
                left = mid + 1;
            else
                right = mid;
        }
    }
    return left;
}

int findRow(const vector<vector<char>> &image, int top, int bottom, bool has) {
    while(top < bottom) {
        int mid = top + (bottom - top) / 2;
        bool found = false;
        for(const char c : image[mid]) {
            if(c == '1') {
                found = true;
                break;
            }
        }
        if(found) {
            if(has)
                bottom = mid;
            else
                top = mid + 1;
        } else {
            if(has)
                top = mid + 1;
            else
                bottom = mid;
        }
    }
    return top;
}

int minArea(vector<vector<char>>& image, int x, int y) {
    int rowCount = image.size(), colCount = image[0].size();
    int left = findColumn(image, 0, y, true), right = findColumn(image, y, colCount, false);
    int top = findRow(image, 0, x, true), bottom = findRow(image, x, rowCount, false);
    return (right - left) * (bottom - top);
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> grid = {{'0','0','1','0'},{'0','1','1','0'},{'0','1','0','0'}};
    cout << minArea(grid, 0, 2) << endl;
    return 0;
}
