//
//  main.cpp
//  208_Implement Trie (Prefix Tree)
//
//  Created by Colin on 13/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include "basic_ds.hpp"

using namespace std;

class Trie {
private:
    class TrieNode{
    public:
        vector<TrieNode *> children;
        bool isLeaf;
        int refCount;
        TrieNode() {
            children = vector<TrieNode *>(26, nullptr);
            isLeaf = false;
            refCount = 0;
        }
    };
    TrieNode *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        ++root->refCount;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto iter = root;
        ++root->refCount;
        for(const char c : word) {
            int index = c - 'a';
            if(iter->children[index] == nullptr) {
                iter->children[index] = new TrieNode();
            }
            iter = iter->children[index];
            ++iter->refCount;
        }
        iter->isLeaf = true;
        return ;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto iter = root;
        for(const char c : word) {
            int index = c - 'a';
            if(iter->children[index] == nullptr) return false;
            iter = iter->children[index];
        }
        return iter->isLeaf;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto iter = root;
        for(const char c : prefix) {
            int index = c - 'a';
            if(iter->children[index] == nullptr) return false;
            iter = iter->children[index];
        }
        return true;
    }
    
    void deleteWord(string word) {
        if(!search(word)) return ;
        helper(word, 0, root);
        return ;
    }
    
    void helper(const string &word, int index, TrieNode *curr) {
        if(index == word.length()) {
            curr->isLeaf = false;
            --curr->refCount;
            return ;
        }
        int d = word[index] - 'a';
        TrieNode *child = curr->children[d];
        helper(word, index + 1, child);
        if(child->refCount == 0) {
            cout << "delete Node for " << word[index] << endl;
            delete child;
        }
        --curr->refCount;
        return ;
    }
    
};
int main(int argc, const char * argv[]) {
    Trie trie = Trie();
    trie.insert("abcd");
    trie.insert("abd");
    trie.insert("bk");
    cout << trie.search("") << endl;
    cout << trie.startsWith("ab") << endl;
    cout << trie.search("bk") << endl;
    cout << trie.startsWith("ak") << endl;
    cout << trie.search("abdc") << endl;
    trie.deleteWord("abd");
    trie.deleteWord("bk");
    trie.deleteWord("abcd");
    return 0;
}
