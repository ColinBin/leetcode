//
//  main.cpp
//  243_Shortest Word Distance
//
//  Created by Colin on 13/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int shortestDistance(vector<string>& words, string word1, string word2) {
    int index1 = -1, index2 = -1;
    int minDistance = INT_MAX;
    for(int i = 0; i < words.size(); ++i) {
        if(words[i] == word1) {
            index1 = i;
        } else if(words[i] == word2) {
            index2 = i;
        }
        if(index1 != -1 && index2 != -1) {
            minDistance = min(minDistance, abs(index1 - index2));
        }
    }
    return minDistance;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
