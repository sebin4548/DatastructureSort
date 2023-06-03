#pragma once
#include <iostream>
#include "Student.h"
#include "Sort.h"
#include <stdio.h>

int Partition(Student values[], int first, int last){
    int pivot;
    int index, smallIndex;

    pivot = last;
    smallIndex = first;
    for (index = first; index < last; index++){
        if (*values[index].getName() < *values[pivot].getName()){
            
            Swap(values[smallIndex], values[index]);
            smallIndex++;
        }
    }
    
    Swap(values[pivot], values[smallIndex]);
    return smallIndex;
}

void QuickSort(Student values[], int first, int last){
    int pivotIndex;
    if (first < last){
        pivotIndex = Partition(values, first, last);
        QuickSort(values, first, pivotIndex - 1);
        QuickSort(values, pivotIndex + 1, last);
    }
}
