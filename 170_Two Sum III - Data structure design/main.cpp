//
//  main.cpp
//  170_Two Sum III - Data structure design
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++records[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto record : records) {
            int i = record.first, j = value - i;
            if(records.find(j) == records.end())
                continue;
            if(i != j || (i == j && record.second > 1))
                return true;
        }
        return false;
    }
private:
    unordered_map<int, int> records;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
