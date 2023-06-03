//
//  BubbleSort.cpp
//  test_project
//
//  Created by KWON SEBIN on 2023/06/02.
//
#include "Student.h"
#include <stdio.h>
void BubbleUp(Student values[], int start, int end){
    for(int index = end; index > start; index--){
        if(*values[index].getName() < *values[index -1].getName())
            Swap(values[index], values[index -1]);
    }
}
void BubbleSort(Student values[], int numValues){
    int current = 0;
    while(current < numValues -1){
        BubbleUp(values, current, numValues -1);
        current++;
    }
    
}

