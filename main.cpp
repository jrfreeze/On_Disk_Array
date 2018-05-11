// Add line to test git hub push

// Driver to test OnDiskArray templatized class which creates a random access on disk array.
//
//  main.cpp
//  OnDiskArray
//
//  Created by Joshua on 4/2/18.
//  Copyright © 2018 Joshua. All rights reserved.
//

#include <iostream>
#include <string>
#include "OnDiskArray.h"

int main() {
    char filename[]{"MyInts"};  // name the file to hold the array
    int testint;    // hold variable retrieved from the file
    OnDiskArray<int> Ints(filename, 10);    // Declare the initial array
    Ints.Set(2, 14);    // Assign three array elements
    Ints.Set(5, 74);
    Ints.Set(7, 9);
    testint = Ints.Get(2);  // Retrieve and print the value of two array elements
    cout << "Element two: " << testint << endl;
    testint = Ints.Get(7);
    cout << "Element seven: " << testint << endl;
    return 0;
}

