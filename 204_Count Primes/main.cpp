//
//  main.cpp
//  204_Count Primes
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    if(n <= 1)
        return 0;
    vector<bool> isPrime(n, true);
    int primeCount = 0;
    for(int i = 2; i < n; ++i) {
        if(isPrime[i]) {
            ++primeCount;
            for(int j = 2; i * j < n; ++j) {
                isPrime[i * j] = false;
            }
        }
    }
    return primeCount;
}

int main(int argc, const char * argv[]) {
    cout << countPrimes(18) << endl;
    return 0;
}
