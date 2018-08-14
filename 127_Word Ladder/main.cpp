//
//  main.cpp
//  127_Word Ladder
//
//  Created by Colin on 20/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int wordCount = wordList.size();
    if(wordCount == 0) return 0;
    int wordLen = wordList[0].size();
    unordered_set<string> set1;
    unordered_set<string> set2;
    unordered_set<string> dict;
    for(const string &word : wordList)
        dict.insert(word);
    set1.insert(beginWord);
    set2.insert(endWord);
    if(dict.find(beginWord) != dict.end()) dict.erase(beginWord);
    if(dict.find(endWord) == dict.end()) return 0;
    else dict.erase(endWord);
    int layer = 2;
    while(!set1.empty() && !set2.empty()) {
        if(set1.size() > set2.size()) swap(set1, set2);
        unordered_set<string> temp;
        for(string current : set1) {
            for(int index = 0; index < wordLen; ++index) {
                const char before = current[index];
                for(int i = 0; i < 26; ++i) {
                    current[index] = 'a' + i;
                    if(set2.find(current) != set2.end()) return layer;
                    if(dict.find(current) != dict.end()) {
                        temp.insert(current);
                        dict.erase(current);
                    }
                }
                current[index] = before;
            }
        }
        ++layer;
        swap(temp, set1);
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
