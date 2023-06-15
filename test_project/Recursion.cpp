//
//  Recursion.cpp
//  test_project
//
//  Created by KWON SEBIN on 2023/06/15.
//
#include<iostream>
using namespace std;

#include "Recursion.hpp"
struct NodeType{
    int info;
    NodeType* next;
};

class SortedType{
public:
private:
    NodeType* listData;
};

void RevPrint(NodeType* listPtr){
    if(listPtr!= NULL){
        RevPrint(listPtr ->next);
        cout<<listPtr->info;
    }
}
