//
//  OnDiskArray.cpp
//  OnDiskArray
//
//  Created by Joshua on 4/2/18.
//  Copyright © 2018 Joshua. All rights reserved.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "OnDiskArray.h"
//
// Constructor - Create initial blank array on the disk
template <typename T>
OnDiskArray<T>::OnDiskArray(char *FileName, int MaxValues) {
    arrayfile = FileName;   // Constructor takes parameters for the file name and size
    size = MaxValues;
    // stream is opened for both in and out so an already open file can be used in either mode.
    arrayStream.open(arrayfile, ios::out | ios::in | ios::binary);
    
    // Check if the file could be opened before creating the array on disk
    if(!arrayStream) {
        cerr << "Could not open file. Constructor" << endl;
        exit(EXIT_FAILURE);
    }
    T itemSpace;
    // Write the blank file to disk of the size indicated in the parameter
    for (int i{0}; i < size; ++i) {
        arrayStream.write(
                          reinterpret_cast<const char*>(&itemSpace), sizeof(T));
    }
}

// Destructor - closes the filestream.
template <typename T>
OnDiskArray<T>::~OnDiskArray() {
    arrayStream.close();
}

// Set member of the array on the disk
template <typename T>
void OnDiskArray<T>::Set(int index, T item) {
    // Check if file is open. Open it if it is not.
    if (!(arrayStream.is_open()))  {
        arrayStream.open(arrayfile, ios::out | ios::binary); }
    // Check if the file could be opened before writing to it
    if(!arrayStream) {
        cerr << "Could not open file. Set" << endl;
        exit(EXIT_FAILURE);
    }
    // Move the file pointer to the correct position for the element being set
    arrayStream.seekp(index * sizeof(T));
    // Write the element to the array.
    arrayStream.write(reinterpret_cast<const char*>(&item), sizeof(T));
}

// Get member of the array from the disk
template <typename T>
T OnDiskArray<T>::Get(int index) {
    // Check if file is open. Open it if it is not.
    if (!(arrayStream.is_open()))  {
        arrayStream.open(arrayfile, ios::out | ios::binary); }
    // Check if the file could be opened before reading from it
    if(!arrayStream) {
        cerr << "Could not open file. Get" << endl;
        exit(EXIT_FAILURE);
    }
    // Move the file pointer to the correct position for the element being read
    arrayStream.seekg(index * sizeof(T));
    // define member of the class to hold the requested element for returning.
    T item;
    arrayStream.read(reinterpret_cast<char*>(&item), sizeof(T));
    
    return item;
}

// Forces compiler to instantiante class for int. Necessary to avoid linker error.
// This will be required for every class that array is to hold. Alternatively, we
// could move the code for at least the constructor implementation to the header.
template class OnDiskArray<int>;


