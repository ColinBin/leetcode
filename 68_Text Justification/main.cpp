//
//  main.cpp
//  68_Text Justification
//
//  Created by Colin on 28/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int wordCount = words.size();
    if(wordCount == 0) return result;
    int i = 0;
    while(i != wordCount) {
        string current = words[i];
        int size = 1;
        int remainLen = maxWidth - current.length();
        ++i;
        while(i != wordCount && remainLen >= words[i].length() + size) {
            remainLen -= words[i].length();
            ++size;
            ++i;
        }
        if(size == 1) {
            string padding(remainLen, ' ');
            result.push_back(current + padding);
        } else {
            int average = remainLen / (size - 1);
            int extras = remainLen % (size - 1);
            int last = 0;
            if(i == wordCount){
                average = 1;
                extras = 0;
                last = remainLen - (size - 1);
            }
            for(int j = i - size + 1; j < i; ++j) {
                string padding(average, ' ');
                if(extras > 0) {
                    padding += ' ';
                    --extras;
                }
                current += padding;
                current += words[j];
            }
            current += string(last, ' ');
            result.push_back(current);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
