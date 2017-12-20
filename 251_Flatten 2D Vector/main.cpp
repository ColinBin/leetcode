//
//  main.cpp
//  251_Flatten 2D Vector
//
//  Created by Colin on 19/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
public:
    
    Vector2D(vector<vector<int>>& vec2d) {
        vecEnd = vec2d.end();
        vecIter = vec2d.begin();
        while(vecIter != vecEnd) {
            if(vecIter->begin() != vecIter->end()) {
                eleIter = vecIter->begin();
                break;
            }
            ++vecIter;
        }
    }
    
    int next() {
        int val = *eleIter;
        ++eleIter;
        if(eleIter == vecIter->end()) {
            ++vecIter;
            while(vecIter != vecEnd) {
                if(vecIter->begin() != vecIter->end()) {
                    eleIter = vecIter->begin();
                    break;
                }
                ++vecIter;
            }
        }
        return val;
    }
    
    bool hasNext() {
        return vecIter != vecEnd;
    }
private:
    vector<vector<int>>::iterator vecIter, vecEnd;
    vector<int>::iterator eleIter;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
