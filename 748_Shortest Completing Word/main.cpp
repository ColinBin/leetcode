//
//  main.cpp
//  748_Shortest Completing Word
//
//  Created by Colin on 16/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string shortestCompletingWord(string licensePlate, vector<string>& words) {
    unordered_map<char, int> record;
    for(const char ch : licensePlate) {
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
            ++record[tolower(ch)];
        }
    }
    int minLen = INT_MAX;
    string result;
    for(const string &word : words) {
        unordered_map<char, int> current;
        bool valid = true;
        for(const char ch : word) {
            ++current[ch];
        }
        for(const auto & ele : record) {
            if(current[ele.first] < record[ele.first]) {
                valid = false;
                break;
            }
        }
        if(valid && word.length() < minLen) {
            result = word;
            minLen = word.length();
        }
        
    }
    return result;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
