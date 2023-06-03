#pragma once
#include <iostream>
#include "Student.h"
#include "Sort.h"
void ReheapDown(Student values[], int root, int bottom){
    int maxChild;
    int rightChild;
    int leftChild;
    
    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    
    if(leftChild < bottom){
        if(leftChild == bottom)
            maxChild = leftChild;
        else{
            if(*values[leftChild].getName() <= *values[rightChild].getName())
                maxChild = rightChild;
            else
                maxChild = leftChild;
            
            }
        if(*values[root].getName() <= *values[maxChild].getName()){
            Swap(values[root], values[maxChild]);
            ReheapDown(values, maxChild, bottom);
        }
    }
}

void HeapSort(Student values[], int numValues){
    int index;
    
    for(index = numValues/2 -1; index >= 0; index--){
        ReheapDown(values, index, numValues - 1);
    }
    for(index = numValues -1; index>= 1; index--){
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
}
