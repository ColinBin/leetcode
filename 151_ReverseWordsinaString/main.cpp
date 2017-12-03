//
//  main.cpp
//  151_ReverseWordsinaString
//
//  Created by Colin on 03/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void reverseWords(string &s) {
    reverse(s.begin(), s.end());
    int sLen = s.length();
    int nextIndex = 0;
    for(int i = 0; i < sLen; ++i) {
        if(s[i] != ' ') {
            if(nextIndex != 0)
                s[nextIndex++] = ' ';
            int j = i;
            while(j < sLen && s[j] != ' ') s[nextIndex++] = s[j++];
            reverse(s.begin() + nextIndex - (j - i), s.begin() + nextIndex);
            i = j;
        }
    }
    s.erase(s.begin() + nextIndex, s.end());
    return;
}

int main(int argc, const char * argv[]) {
    string s = "the sky is blue";
    reverseWords(s);
    cout << s << endl;
    return 0;
}
