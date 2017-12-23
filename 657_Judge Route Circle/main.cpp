//
//  main.cpp
//  657_Judge Route Circle
//
//  Created by Colin on 22/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool judgeCircle(string moves) {
    unordered_map<char, int> record;
    for(const char ch : moves) {
        ++record[ch];
    }
    return record['L'] == record['R'] && record['U'] && record['D'];
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
