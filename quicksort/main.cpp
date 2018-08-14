//
//  main.cpp
//  quicksort
//
//  Created by Colin on 08/02/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int partition(vector<int> &arr, int lo, int hi) {
    int pivot = arr[hi];
    int i = lo;
    for(int index = lo; index < hi; ++index) {
        if(arr[index] <= pivot) {
            swap(arr[index], arr[i]);
            ++i;
        }
    }
    swap(arr[hi], arr[i]);
    return i;
}

void quicksort(vector<int> &arr, int lo, int hi) {
    if(lo < hi) {
        int p = partition(arr, lo, hi);
        quicksort(arr, lo, p - 1);
        quicksort(arr, p + 1, hi);
    }
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {1,1,1,1,1,1};
    quicksort(arr, 0, arr.size() - 1);
    for(const int ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
