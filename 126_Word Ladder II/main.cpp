//
//  main.cpp
//  126_Word Ladder II
//
//  Created by Colin on 20/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> res;
    int wordCount = wordList.size();
    if(wordCount == 0) return res;
    int wordLen = wordList[0].size();
    unordered_set<string> dict;
    for(const string &word : wordList)
        dict.insert(word);
    if(dict.find(endWord) == dict.end()) return res;
    queue<pair<string, vector<string>>> q;
    vector<string> initial = {beginWord};
    q.push({beginWord, initial});
    bool done = false;
    while(!done && !q.empty()) {
        int layerSize = q.size();
        set<string> toRemove;
        for(int i = 0; i < layerSize; ++i) {
            auto ele = q.front();
            q.pop();
            string &current = ele.first;
            for(int index = 0; index < wordLen; ++index) {
                const char before = current[index];
                for(int j = 0; j < 26; ++j) {
                    current[index] = j + 'a';
                    if(dict.find(current) != dict.end()) {
                        if(toRemove.find(current) == toRemove.end()) toRemove.insert(current);
                        if(current == endWord) {
                            done = true;
                            auto arr = ele.second;
                            arr.push_back(endWord);
                            res.push_back(arr);
                        } else {
                            auto arr = ele.second;
                            arr.push_back(current);
                            q.push(make_pair(current, arr));
                        }
                    }
                }
                current[index] = before;
            }
        }
        for(const string &word : toRemove) {
            dict.erase(word);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
