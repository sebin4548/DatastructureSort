#include <iostream>
#include "Student.h"
#include "Sort.h"
#include "heap.cpp"
#include "DepthFirstSearch.cpp"

using namespace std;
int main(){
    
    try{
//        Print(cout, stu, 3);
    //     cout<<('a'<'b');
        PQType<int> pq(10);
        pq.EnQueue(10);
        pq.EnQueue(0);
        pq.EnQueue(15);
        pq.EnQueue(20);
        pq.EnQueue(30);
        pq.EnQueue(320);
        pq.EnQueue(3);
        
        pq.EnQueue(30);
        pq.EnQueue(3200);
        pq.EnQueue(3);
        cout<<pq.Dequeue()<<endl;
        cout<<pq.Dequeue()<<endl;
        cout<<pq.Dequeue()<<endl;
        cout<<pq.Dequeue();
    }
    catch(FullPq){

    }
    catch(EmptyPq){

    }
    GraphType<char> xx;
    xx.add('A', 'D');
    xx.add('D', 'f');
    xx.add('f', 'H');
    DepthFirstSearch(xx, 'A', 'H');
}
