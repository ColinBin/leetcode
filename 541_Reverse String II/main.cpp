//
//  main.cpp
//  541_Reverse String II
//
//  Created by Colin on 24/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void reversePart(string &s, int left, int right) {
    if(right >= s.length()) {
        right = s.length() - 1;
    }
    while(left < right) {
        swap(s[left], s[right]);
        ++left;
        --right;
    }
    return;
}

string reverseStr(string s, int k) {
    if(k <= 1)
        return s;
    int left = 0, right = k - 1;
    int interval = k * 2;
    while(left < s.length() - 1) {
        reversePart(s, left, right);
        left += interval;
        right = left + k - 1;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    cout << reverseStr("abcdabcdmnf", 2) << endl;
    return 0;
}
