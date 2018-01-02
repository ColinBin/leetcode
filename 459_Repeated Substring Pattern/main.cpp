//
//  main.cpp
//  459_Repeated Substring Pattern
//
//  Created by Colin on 31/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool repeatedSubstringPattern(string s) {
    return (s + s).substr(1, s.length() * 2 - 2).find(s) != string::npos;
}

int main(int argc, const char * argv[]) {

    return 0;
}
