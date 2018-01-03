//
//  main.cpp
//  425_Word Squares
//
//  Created by Colin on 02/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class Solution {
private:
    class TrieNode {
    private:
        vector<TrieNode *> children;
        vector<string> buffer;
        bool isComplete =false;
    public:
        TrieNode() {
            children = vector<TrieNode *> (26, nullptr);
        }
        TrieNode * getChild(const char c) {
            return children[c - 'a'];
        }
        void setChild(const char c) {
            children[c - 'a'] = new TrieNode;
        }
        void insertWord(const string &word) {
            buffer.push_back(word);
            return;
        }
        const vector<string> &getWords() {
            return buffer;
        }
    };
    const vector<string> empty;
    TrieNode *buildTrie(const vector<string> &words) {
        TrieNode *root = new TrieNode;
        for(const string &s : words) {
            TrieNode *iter = root;
            for(const char c : s) {
                if(iter->getChild(c) == nullptr) {
                    iter->setChild(c);
                }
                iter = iter->getChild(c);
                iter->insertWord(s);
            }
        }
        return root;
    }
    const vector<string> &getMatch(TrieNode *current, const string &prefix) {
        for(const char c : prefix) {
            if(current->getChild(c) == nullptr)
                return empty;
            else
                current = current->getChild(c);
        }
        return current->getWords();
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int wordCount = words.size();
        int wordLen = words[0].size();
        TrieNode *root = buildTrie(words);
        vector<vector<string>> res;
        vector<string> tempList;
        for(const string &word : words) {
            tempList.push_back(word);
            helper(root, res, 1, wordLen, tempList);
            tempList.pop_back();
        }
        return res;
    }
    
    void helper(TrieNode *root, vector<vector<string>> &res, int index, const int wordLen, vector<string> &tempList) {
        if(index == wordLen) {
            res.push_back(tempList);
            return;
        }
        string currentPrefix = "";
        for(int i = 0; i < index; ++i) {
            currentPrefix += tempList[i][index];
        }
        const vector<string> &matches = getMatch(root, currentPrefix);
        for(const string &match : matches) {
            tempList.push_back(match);
            helper(root, res, index + 1, wordLen, tempList);
            tempList.pop_back();
        }
        return;
    }
    
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
