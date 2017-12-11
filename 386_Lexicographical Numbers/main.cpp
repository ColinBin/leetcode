//
//  main.cpp
//  386_Lexicographical Numbers
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> lexicalOrder(int n) {
    vector<int> res;
    int count = 0;
    int current = 1;
    while(count < n) {
        res.push_back(current);
        if(current * 10 <= n)
            current *= 10;
        else if(current % 10 != 9 && current + 1 <= n)
            current += 1;
        else {
            while(current % 10 == 9 || current >= n) {
                current /= 10;
            }
            current += 1;
        }
        ++count;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    auto res = lexicalOrder(50);
    for(auto ele : res) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
