#pragma once
#include <iostream>
#include "Student.h"
#include "Sort.h"

int MinIndex(Student values[], int start, int end){
    int indexOfMin = start;
    for(int index = start + 1; index <= end; index ++){
        if(*values[index].getName() < *values[indexOfMin].getName())
            indexOfMin = index;
        
    }
    return indexOfMin;
}

void SelectionSort(Student values[], int numValues){
    int endIndex = numValues - 1;
    for(int current = 0; current<endIndex; current++){
       
        Swap(values[current], values[MinIndex(values, current, endIndex)]);
    }
}
