#pragma once
#include <iostream>
#include "Student.h"
#include "Sort.h"

void InsertItem(Student values[], int start, int end){
    bool finished = false;
    int current = end;
    bool moreToSearch = ( current != start);
    
    while(moreToSearch && !finished){
        if(*values[current].getName() < *values[current -1].getName()){
            Swap(values[current], values[current - 1]);
            current--;
            moreToSearch = (current != start);
        }
        else
            finished = true;
    }
}

void InsertionSort(Student values[], int numValues){
    for(int count = 0; count < numValues; count++){
        InsertItem(values, 0, count);
    }
}
