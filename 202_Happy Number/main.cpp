//
//  main.cpp
//  202_Happy Number
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

bool isHappy(int n) {
    set<int> appear;
    while(n != 1) {
        if(appear.find(n) != appear.end())
            return false;
        appear.insert(n);
        int newN = 0;
        while(n != 0) {
            newN += (n % 10) * (n % 10);
            n /= 10;
        }
        n = newN;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << isHappy(19) << endl;
    return 0;
}
