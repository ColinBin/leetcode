//
//  main.cpp
//  168_Excel Sheet Column Title
//
//  Created by Colin on 21/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

string convertToTitle(int n) {
    string res = "";
    do {
        --n;
        int current = n % 26;
        res += current + 'A';
        n /= 26;
        
    } while(n != 0);
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, const char * argv[]) {
    cout << convertToTitle(27) << endl;
    return 0;
}
