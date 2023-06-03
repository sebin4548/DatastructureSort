

#include<iostream>
using namespace std;
//class PQType;
template<class ItemType>
void Swap(ItemType &a, ItemType &b){
    ItemType temp = a;
    a = b;
    b = temp;
}
template <class ItemType>
class HeapType{
public:
    //recursive와 while문을 이용한 방법 모두 구현해두었습니다. ReheapUp/Down은 recursive하게, ReheapUp/Down_Non은 while문으로 구현하였습니다.
    void ReheapDown(int root, int bottom){
        int maxChild;
        int rightChild = root * 2 + 2;
        int leftChild = root * 2 + 1;
        
        if(leftChild <= bottom) //나중에 재귀로 연습하기
        {
            if(leftChild == bottom)
                maxChild = leftChild;
            else{
                if(elements[leftChild] <= elements[rightChild])
                    maxChild = rightChild;
                else
                    maxChild = leftChild;
            }
            if(elements[root] < elements[maxChild]){
                Swap(elements[root], elements[maxChild]);
                ReheapDown(maxChild, bottom);
            }
        }
        
    }
    void ReheapDown_Non(int root, int bottom){
        int maxChild;
        int rightChild = root * 2 + 2;
        int leftChild = root * 2 + 1;
        do{
            rightChild = root * 2 + 2;
            leftChild = root * 2 + 1;
            
            if(leftChild <= bottom)
            {
                if(leftChild == bottom)
                    maxChild = leftChild;
                else{
                    if(elements[leftChild] <= elements[rightChild])
                        maxChild = rightChild;
                    else
                        maxChild = leftChild;
                }
                if(elements[root] < elements[maxChild]){
                    Swap(elements[root], elements[maxChild]);
//                    ReheapDown(maxChild, bottom);
                }
            }
        }while(elements[leftChild] <= elements[rightChild]);
        
    }
    void ReheapUp(int root, int bottom){
        int parent;
        if(bottom > root){
            parent = (bottom -1) /2;
            if(elements[parent] < elements[bottom]){
                Swap(elements[parent], elements[bottom]);
                ReheapUp(root, parent);
            }
        }
    }
    void ReheapUp_Non(int root, int bottom){
        int parent = (bottom -1) /2;
        do{
            if(bottom > root){
                parent = (bottom -1) /2;
                if(elements[parent] < elements[bottom]){
                    Swap(elements[parent], elements[bottom]);
                    
                }
            }
        } while(elements[parent] < elements[bottom]);
        
    }
    
    
    ItemType* elements;
    
    int numElements;
//public:
//    friend class PQType;
};
class FullPQ{
    
};
class EmptyPQ{
    
};

template<class ItemType>
class PQType{
public:
    PQType(int n){
        items.elements = new ItemType[n];
    }
    ~PQType(){
        delete[] items.elements;
    }
//    void MakeEmpty();
//    bool IsEmpty();
//    bool IsFull() const;
    void Enqueue(ItemType newItem){
        if(numItems == maxItems) throw FullPQ();
        else{
            numItems ++;
            items.elements[numItems -1] = newItem;
            items.ReheapUp_Non(0, numItems - 1);
        }
        maxItems = (items.elements[0]);
        cout<<"현재까지 입력된 가장 큰 값은"<<(items.elements[0])<<endl;
    }
    void Dequeue(ItemType &item){
        if(numItems == 0) throw EmptyPQ();
        else{
            item = items.elements[0];
            items.elements[0] = items.elements[numItems - 1];
            numItems--;
            items.ReheapDown_Non(0, numItems -1);
        }
    }
private:
    int numItems;
    HeapType<ItemType> items;
    int maxItems;
};

int main(){
    PQType<int> x(4);
    x.Enqueue(10);
    x.Enqueue(15);
    x.Enqueue(30);
    x.Enqueue(0);
    int deq;
    x.Dequeue(deq);
    x.Enqueue(20);
    x.Dequeue(deq);
    cout<<"dequeue 된 값" << deq<<endl;
    x.Enqueue(18);
}
