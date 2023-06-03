#include <iostream>
#include "Student.h"
#include "Sort.h"


using namespace std;
int main(){
    Student stu[3];
    char *x = "abc";
    char *y = "def";
    char *z = "cc";
    stu[0].InitValue(0, x, 4.0);

    stu[1].InitValue(1, y, 3.5);
    stu[2].InitValue(1, z, 3.5);
//    InsertionSort(stu, 3);
//    QuickSort(stu, 0, 3);
    BubbleSort(stu, 3);
    
    Print(cout, stu, 3);
//     cout<<('a'<'b');

}
