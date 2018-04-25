// This class creates a templatized array on a disk that can be written to and read from
// in a random access mode. File is written in binary to permit any data type to be used.

//
//  OnDiskArray.hpp
//  OnDiskArray
//
//  Created by Joshua on 4/2/18.
//  Copyright © 2018 Joshua. All rights reserved.
//

#ifndef OnDiskArray_h
#define OnDiskArray_h

#include <fstream>
#include <stdio.h>

using namespace std;

// Create a templatized class for on disk random access reference
template <class T>
class OnDiskArray {
private:
    string arrayfile;  // name of the file on disk
    int size;          // maximum number of elements of the array
    fstream arrayStream;  // stream to access the file on disk
public:
    OnDiskArray(char *FileName, int MaxValues);     // Constructor
    ~OnDiskArray();                                 // Destructor
    void Set(int index, T value);                   // Set member of the array on the disk
    T Get(int index);                               // Get member of the array from the disk
};
#endif /* OnDiskArray_h */

