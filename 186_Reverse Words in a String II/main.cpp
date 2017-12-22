//
//  main.cpp
//  186_Reverse Words in a String II
//
//  Created by Colin on 21/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "basic_ds.hpp"

using namespace std;

void reverseWords(vector<char>& str) {
    reverse(str.begin(), str.end());
    auto currStart = str.begin(), currEnd = str.begin();
    while(currEnd != str.end()) {
        while(currEnd != str.end() && *currEnd != ' ')
            ++currEnd;
        reverse(currStart, currEnd);
        currStart = currEnd;
        while(currStart != str.end() && *currStart == ' ')
            ++currStart;
        currEnd = currStart;
    }
    return ;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
