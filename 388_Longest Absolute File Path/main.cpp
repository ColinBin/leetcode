//
//  main.cpp
//  388_Longest Absolute File Path
//
//  Created by Colin on 08/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

vector<string> getSet(string input) {
    istringstream is(input);
    string temp;
    vector<string> pathSet;
    while(getline(is, temp)) {
        pathSet.push_back(temp);
    }
    return pathSet;
}

int getLevel(const string &s) {
    int level = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '\t')
            ++level;
        else
            break;
    }
    return level;
}

int lengthLongestPath(string input) {
    vector<string> pathSet = getSet(input);
    stack<int> stk;
    stk.push(-1);
    int maxLen = 0;
    for(string &s : pathSet) {
        int level = getLevel(s);
        while(stk.size() - 1 > level)
            stk.pop();
        int currentLen = stk.top() + s.length() - level + 1;
        stk.push(currentLen);
        if(s.find(".") != string::npos) {
            maxLen = max(maxLen, currentLen);
        }
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    cout << lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") << endl;
    return 0;
}
