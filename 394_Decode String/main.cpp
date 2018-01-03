//
//  main.cpp
//  394_Decode String
//
//  Created by Colin on 02/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isNum(char c) {
    return c >= '0' && c <= '9';
}

string helper(const string &s, int &index) {
    string current = "";
    static const int sLen = s.length();
    while(index < sLen) {
        if(s[index] == ']') break;
        if(!isNum(s[index])) {
            current += s[index];
            ++index;
        } else {
            int freq = 0;
            while(s[index] != '[') {
                freq = freq * 10 + s[index] - '0';
                ++index;
            }
            ++index;
            string subStr = helper(s, index);
            ++index;
            for(int i = 0; i < freq; ++i) {
                current += subStr;
            }
        }
    }
    return current;
}

string decodeString(string s) {
    int index = 0;
    return helper(s, index);
}

int main(int argc, const char * argv[]) {
    cout << decodeString("2[abc]3[cd]ef") << endl;
    return 0;
}
