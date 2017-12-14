//
//  main.cpp
//  208_Implement Trie (Prefix Tree)
//
//  Created by Colin on 13/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *currentNode = root;
        for(const char ch : word) {
            if(!currentNode->containsChild(ch)) {
                currentNode->insert(ch);
            }
            currentNode = currentNode->getChild(ch);
        }
        currentNode->setComplete(true);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *currentNode = root;
        for(const char ch : word) {
            if(!currentNode->containsChild(ch))
                return false;
            currentNode = currentNode->getChild(ch);
        }
        return currentNode->checkComplete();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *currentNode = root;
        for(const char ch : prefix) {
            if(!currentNode->containsChild(ch)) {
                return false;
            }
            currentNode = currentNode->getChild(ch);
        }
        return true;
    }
    

private:
    class TrieNode {
    public:
        TrieNode(bool complete = false): isComplete(complete) {  }
        void insert(char newChar) {
            childNodes[newChar] = new TrieNode(false);
            return;
        }
        bool containsChild(char targetChar) {
            return childNodes.find(targetChar) != childNodes.end();
        }
        TrieNode *getChild(char targetChar) {
            return childNodes[targetChar];
        }
        void setComplete(bool complete) {
            isComplete = complete;
        }
        bool checkComplete() {
            return isComplete;
        }
    private:
        unordered_map<char, TrieNode *> childNodes;
        bool isComplete;
    };
    TrieNode *root;
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
    return 0;
}
