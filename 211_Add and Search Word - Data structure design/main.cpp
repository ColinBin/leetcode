//
//  main.cpp
//  211_Add and Search Word - Data structure design
//
//  Created by Colin on 17/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode(false);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *dummy = root;
        for(const char ch : word) {
            if(dummy->getChild(ch) == nullptr) {
                dummy->newChild(ch);
            }
            dummy = dummy->getChild(ch);
        }
        dummy->setComplete(true);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return findWord(word, 0, root);
    }
private:
    class TrieNode {
    public:
        TrieNode(bool complete = false): isComplete(complete) {
            children = vector<TrieNode *> (26, nullptr);
        }
        void newChild(const char ch) { children[ch - 'a'] = new TrieNode(); return; }
        TrieNode *getChild(const char ch) { return children[ch - 'a']; }
        void setComplete(bool complete) { isComplete = complete; }
        bool getComplete() { return isComplete; }
    private:
        vector<TrieNode *> children;
        bool isComplete;
    };
    bool findWord(const string &word, int index, TrieNode* current) {
        if(index == word.length()) {
            if(current->getComplete())
                return true;
            else
                return false;
        }
        char currentChar = word[index];
        if(currentChar >= 'a' && currentChar <= 'z') {
            if(current->getChild(currentChar) == nullptr) {
                return false;
            } else {
                return findWord(word, index + 1, current->getChild(currentChar));
            }
        } else {
            for(int i = 0; i < 26; ++i) {
                char nextChar = 'a' + i;
                if(current->getChild(nextChar) != nullptr) {
                    if(findWord(word, index + 1, current->getChild(nextChar)))
                        return true;
                }
            }
        }
        return false;
    }
    TrieNode *root;
};

int main(int argc, const char * argv[]) {
    WordDictionary dict;
    dict.addWord("hello");
    dict.addWord("colin");
    cout << dict.search("hello") << endl;
    cout << dict.search("bob") << endl;
    return 0;
}
