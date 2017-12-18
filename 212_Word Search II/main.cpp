//
//  main.cpp
//  212_Word Search II
//
//  Created by Colin on 17/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode() {
        children = vector<TrieNode *> (26, nullptr);
        word = "";
    }
    string getWord() {
        return word;
    }
    void setWord(const string &newWord) {
        word = newWord;
    }
    TrieNode *getChild(const char ch) {
        return children[ch - 'a'];
    }
    TrieNode *newChild(const char ch) {
        children[ch - 'a'] = new TrieNode();
        return children[ch - 'a'];
    }
private:
    string word;
    vector<TrieNode *> children;
};

TrieNode *getTrie(vector<string> &words) {
    TrieNode *root = new TrieNode();
    for(const string &word : words) {
        TrieNode *iter = root;
        for(const char ch : word) {
            TrieNode *child = iter->getChild(ch);
            if(child == nullptr) {
                child = iter->newChild(ch);
            }
            iter = child;
        }
        iter->setWord(word);
    }
    return root;
}

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vector<vector<char>> &board, vector<string> &res, TrieNode *current, int i, int j) {
    char ch = board[i][j];
    if(ch == '#' || current->getChild(ch) == nullptr)
        return;
    if(current->getWord() != "") {
        res.push_back(current->getWord());
        current->setWord("");
    }
    current = current->getChild(ch);
    board[i][j] = '#';
    for(const auto &direction : directions) {
        int new_i = i + direction.first, new_j = j + direction.second;
        if(new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size()) {
            dfs(board, res, current, new_i, new_j);
        }
    }
    board[i][j] = ch;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> res;
    int wordCount = words.size();
    int rowCount = board.size();
    if(rowCount == 0 || wordCount == 0)
        return res;
    int colCount = board[0].size();
    TrieNode *root = getTrie(words);
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            dfs(board, res, root, i, j);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
