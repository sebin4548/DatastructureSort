template <typename T>
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
class HeapType{
public:
    
    void ReheapDown(int root, int bottom){
        int maxChild;
        int rightChild;
        int leftChild;
        
        leftChild = root*2 + 1;
        rightChild = root * 2 +2;
        
        if(leftChild<= bottom){
            if(leftChild == bottom)
                maxChild = leftChild;
            
            else{
                if(elements[leftChild] <= elements[rightChild])
                    maxChild = rightChild;
                else
                    maxChild = leftChild;
            }
            if(elements[root] < elements[maxChild]){
                Swap(elements[root] < elements[maxChild]);
                ReheapDown(maxChild, bottom);
            }
        }
    }
    void ReheapUp(int root, int bottom){
        int parent;
        if(bottom > root){
            parent = (bottom - 1)/2;
            if(elements[parent] < elements[bottom]){
                Swap(elements[parent], elements[bottom]);
                ReheapUp(root, parent);
            }
        }
    }
    T* elements;
    int numElements;
};
class EmptyPq{
    
};
class FullPq{
    
};
template <typename T>
class PQType{
    int numItems;
    HeapType<T> items;
    int maxItems;
public:
    PQType(int n){
        maxItems = n;
        numItems = 0;
        items.elements = new T [n];
    }
    void Dequeue(T& item){
        if(numItems == 0)
            throw EmptyPq();
        else{
            item = items.elements[0];
            items.elements[0] = items.elements[numItems -1];
            numItems--;
            items.ReheapDown(0, numItems -1);
        }
    }
    void EnQueue(T newItem){
        if(numItems == maxItems){
            throw FullPq();
        } else {
            numItems++;
            items.elements[numItems - 1] = newItem;
            items.ReheapUp(0, numItems -1);
        }
    }
};
