//
//  main.cpp
//  245_Shortest Word Distance III
//
//  Created by Colin on 13/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int index1 = -1, index2 = -1;
    int minDist = INT_MAX;
    for(int i = 0; i < words.size(); ++i) {
        if(words[i] == word1) {
            if(index1 != -1 && word1 == word2)
                minDist = min(minDist, i - index1);
            index1 = i;
        } else if(words[i] == word2) {
            index2 = i;
        }
        if(index1 != -1 && index2 != -1 && word1 != word2)
            minDist = min(minDist, abs(index1 - index2));
    }
    
    return minDist;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
