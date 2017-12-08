//
//  main.cpp
//  223Rectangle Area
//
//  Created by Colin on 08/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left1 = min(A, C), right1 = max(A, C), bottom1 = min(B, D), top1 = max(B, D);
    int left2 = min(E, G), right2 = max(E, G), bottom2 = min(F, H), top2 = max(F, H);
    int targetLeft = max(left1, left2), targetBottom = max(bottom1, bottom2);
    int targetRight = min(right1, right2), targetTop = min(top1, top2);
    int overlap = 0;
    if(targetLeft < targetRight && targetBottom < targetTop)
        overlap = (targetRight - targetLeft) * (targetTop - targetBottom);
    return (right1 - left1) * (top1 - bottom1) + (right2 - left2) * (top2 - bottom2) - overlap;
}

int main(int argc, const char * argv[]) {
    cout << computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}
