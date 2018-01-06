//
//  main.cpp
//  412_Fizz Buzz
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<string> fizzBuzz(int n) {
    int i = 0;
    vector<string> res;
    while(i < n) {
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back("Fizz");
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back("Buzz");
        if(i++ < n) res.push_back("Fizz");
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back("Fizz");
        if(i++ < n) res.push_back("Buzz");
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back("Fizz");
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back(to_string(i));
        if(i++ < n) res.push_back("FizzBuzz");
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
