template<class ItemType>
void Swap(ItemType &x, ItemType &y){
    ItemType temp = x;
    x = y;
    y = temp;
}

template<class ItemType>
void ReheapDown(ItemType values[], int root, int bottom){
    int maxChild;
    int rightChild;
    int leftChild;
    
    if(leftChild <= bottom){
        if(leftChild == bottom)
            maxChild = leftChild;
        else{
            if(values[leftChild] <= values[rightChild])
                maxChild =rightChild;
            else
                maxChild = leftChild;
        }
        if(values[root] < values[maxChild]){
            Swap(values[root], values[maxChild]);
            ReheapDown(values, maxChild, bottom);
        }
    }
}

template <class ItemType>
void HeapSort(ItemType values[], int numValues){
    int index;
    for(index = numValues / 2 -1; index >= 0; index--){
        ReheapDown(values, index, numValues - 1);
    }
    for(index = numValues - 1; index >= 1; index --){
        Swap(values[0], values[index]);
        ReheapDown(values, 0, index - 1);
    }
}
