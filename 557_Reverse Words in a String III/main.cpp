//
//  main.cpp
//  557_Reverse Words in a String III
//
//  Created by Colin on 23/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

string reverseWords(string s) {
    auto wordBegin = s.begin(), wordEnd = s.begin();
    while(wordBegin != s.end() && *wordBegin == ' ')
        ++wordBegin;
    wordEnd = wordBegin;
    while(wordEnd != s.end()) {
        while(wordEnd != s.end() && *wordEnd != ' ')
            ++wordEnd;
        reverse(wordBegin, wordEnd);
        wordBegin = wordEnd;
        while(wordBegin != s.end() && *wordBegin == ' ')
            ++wordBegin;
        wordEnd = wordBegin;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    cout << reverseWords("Hello world") << endl;
    return 0;
}
