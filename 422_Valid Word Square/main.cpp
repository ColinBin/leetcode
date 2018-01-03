//
//  main.cpp
//  422_Valid Word Square
//
//  Created by Colin on 02/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool validWordSquare(vector<string>& words) {
    int wordCount = words.size();
    for(int i = 0; i < wordCount; ++i) {
        int currentLen = words[i].size();
        for(int j = 0; j < currentLen; ++j) {
            if(j >= wordCount || i >= words[j].length() || words[i][j] != words[j][i])
                return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
