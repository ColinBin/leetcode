//
//  main.cpp
//  quickselect
//
//  Created by Colin on 08/02/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

// partition arr into two parts, elements in the first part <= pivot, elements in the second part > pivot, return the end of the first part
int partition(vector<int> &arr, int lo, int hi) {
    int randIndex = rand() % (hi - lo + 1) + lo;
    swap(arr[randIndex], arr[hi]);
    int pivot = arr[hi];
    int index = lo;
    for(int i = lo; i < hi; ++i) {
        if(arr[i] <= pivot) {
            swap(arr[i], arr[index]);
            ++index;
        }
    }
    swap(arr[hi], arr[index]);
    return index;
}

// find the kth largest element in arr
int quickselect(vector<int> &arr, int k) {
    int count = arr.size();
    if(k <= 0 || k > count) return -1;
    int left = 0, right = count - 1;
    while(true) {
        int p = partition(arr, left, right);
        if(count - k == p) return arr[p];
        if(count - k > p) {
            left = p + 1;
        } else {
            right = p - 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {5,2,4,1,6,7,3,9};
    cout << quickselect(arr, 2) << endl;
    return 0;
}
