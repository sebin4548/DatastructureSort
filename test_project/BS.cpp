//#include <iostream>
//using namespace::std;
class SL{
public:
    int id;
    int grade;
    SL(int id, int grade) : id(id), grade(grade){
    }
};

SL* BS(SL values[], int id, int fromLoc, int toLoc){
    int mid = (fromLoc + toLoc)/2;
    if(fromLoc > toLoc) return nullptr;

    if(values[mid].id == id) return &values[mid];
    else if(id < values[mid].id){
        return BS(values, id, fromLoc, mid);
    } else {
        return BS(values, id, mid + 1, toLoc);
    }
}

//int main(){
//
//}

#pragma once
#include<iostream>
using namespace std;

void Print(){
    cout<<"Tlqkf";
}
