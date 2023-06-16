#include <iostream>
using namespace std;
const int NULL_EDGE = 0;
template<class ItemType>
class QueType;

template<class ItemType>
class GraphType{
public:
    GraphType(){
        numVertices = 0;
        maxVertices = 50;
        vertices = new ItemType[50];
        marks = new bool[50];
        edges = new int*[50];
        for(int i = 0; i < 50; i++){
            edges[i] = new int[50];
        }
    }
    GraphType(int maxV){
        numVertices = 0;
        maxVertices = maxV;
        vertices = new ItemType[maxV];
        marks = new bool[maxV];
        edges = new int*[maxV];
        for(int i = 0; i < maxV; i++){
            edges[i] = new int[maxV];
        
        }
    }
    ~GraphType();
    void MakeEmpty(){
        numVertices = 0;
    }
    void AddVertex(ItemType item){
        vertices[numVertices] = item;
        for(int index = 0; index < numVertices; index++){
            edges[numVertices][index] = NULL_EDGE;
            edges[index][numVertices] = NULL_EDGE;
        }
        numVertices++;
    }
    void AddEdge(ItemType start, ItemType end, int weight){
        int startIndex, endIndex;
        startIndex = IndexIs(vertices, start);
        endIndex = IndexIs(vertices, end);
        edges[startIndex][endIndex] = weight;
    }
    int WeightIs(ItemType start, ItemType end){
        int startIndex, endIndex;
        startIndex = IndexIs(vertices, start);
        endIndex = IndexIs(vertices, end);
        return edges[startIndex][endIndex];
    }
    void GetToVertices(ItemType vertex, QueType<ItemType>& adjvertexQ){
        int fromIndex, toIndex;
        fromIndex = IndexIs(vertices, vertex);
        for(toIndex = 0; toIndex < numVertices; toIndex++){
            if(edges[fromIndex][toIndex] != NULL_EDGE)
                adjvertexQ.Enqueue(vertices[toIndex]);
        }
    }
    void ClearMarks(){
        for(int i = 0; i < numVertices; i++){
            marks[i] = false;
        }
    }
    void MarkVertex(ItemType vertex){
        int index;
        index = IndexIs(vertices, vertex);
        marks[index] = true;
    }
    bool IsMarked(ItemType vertex){
        int index;
        index = IndexIs(vertices, vertex);
        return marks[index];
    }
    // void DepthFirstSearch(ItemType startVertex, ItemType endVertex);
    // void BreadthFirstSearch(ItemType startVertex, ItemType endVertex);
private:
    int numVertices;
    int maxVertices;
    ItemType* vertices;
    int** edges;
    bool* marks;
    int IndexIs(ItemType* vertices, ItemType vertex){
        int index = 0;
        while(!(vertex == vertices[index]))
            index++;
        return index;
    }
};

template<class VertexType>
class StackType{
public:
    StackType(){
        maxStack = 500;
        top = -1;
        items = new VertexType[500];
    }
    ~StackType(){
        delete [] items;
    }
    void MakeEmpty(){
        top = -1;
    }
    bool IsEmpty(){
        return (top == -1);
    }
    bool IsFull(){
        return (top == maxStack -1);
    }
    void Push(VertexType item){
        top++;
        items[top] = item;
    }
    void Pop(VertexType& item){
        item = items[top];
        top--;
    }
private:
    int top;
    VertexType* items;
    int maxStack;
};
template<class VertexType>
class StackType{
public:
    StackType(){
        maxStack = 500;
        top = -1;
        items = new VertexType[500];
    }
    ~StackType(){
        delete [] items;
    }
    void MakeEmpty(){
        top = -1;
    }
    bool IsEmpty(){
        return (top == -1);
    }
    bool IsFull(){
        return (top == maxStack -1);
    }
    void Push(VertexType item){
        top++;
        items[top] = item;
    }
    void Pop(VertexType& item){
        item = items[top];
        top--;
    }
private:
    int top;
    VertexType* items;
    int maxStack;
};
template<class VertexType>
class QueType{
public:
    QueType(){
        maxQue = 500;
        front = maxQue -1;
        rear = maxQue -1;
        items = new VertexType[500];
    }
    ~QueType(){
        delete [] items;
    }
    void MakeEmpty(){
        front = maxQue -1;
        rear = maxQue -1;
    }
    bool IsEmpty(){
        return (rear == front);
    }
    bool IsFull(){
        return ((rear + 1) % maxQue == front);
    }
    void Enqueue(VertexType item){
        rear = (rear + 1) % maxQue;
        items[rear] = item;
    }
    void Dequeue(VertexType& item){
        front = (front + 1) % maxQue;
        item = items[front];
    }
private:
    int front;
    int rear;
    VertexType* items;
    int maxQue;
};

template<class VertexType>
void DepthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex){
    StackType<VertexType> stack;
    QueType<VertexType> vertexQ;
    VertexType item;
    VertexType currentVertex;
    bool found = false;
    graph.ClearMarks();
    stack.Push(startVertex);
    do{
        stack.Pop(currentVertex);
        if(currentVertex == endVertex){
            std::cout << currentVertex;
            found = true;
        }
        else{
            graph.GetToVertices(currentVertex, vertexQ);
            while(!vertexQ.IsEmpty() && !found){
                vertexQ.Dequeue(item);
                if(!graph.IsMarked(item)){
                    graph.MarkVertex(item);
                    stack.Push(item);
                }
            }
        }
    }while(!stack.IsEmpty() && !found);
    if(!found)
        std::cout << "Path not found." << std::endl;
}

template<class VertexType>
void BreathFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex){
    QueType<VertexType> queue;
    QueType<VertexType> vertexQ;
    VertexType item;
    VertexType currentVertex;
    graph.ClearMarks();
    queue.Enqueue(startVertex);
    do{
        queue.Dequeue(currentVertex);
        if(currentVertex == endVertex){
            std::cout << currentVertex;
            graph.GetToVertices(currentVertex, vertexQ);
            while(!vertexQ.IsEmpty()){
                vertexQ.Dequeue(item);
                if(!graph.IsMarked(item)){
                    graph.MarkVertex(item);
                    queue.Enqueue(item);
                }
            }
        }
    }while(!queue.IsEmpty());
}
int main(){
    GraphType<char> graph;
    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');
    graph.AddVertex('D');
    graph.AddVertex('E');
    graph.AddVertex('F');
    graph.AddVertex('G');
    graph.AddVertex('H');
    graph.AddVertex('I');
    graph.AddVertex('J');
    graph.AddVertex('K');
    graph.AddVertex('L');
    graph.AddVertex('M');
    graph.AddVertex('N');
    graph.AddVertex('O');
    graph.AddVertex('P');
    graph.AddVertex('Q');
    graph.AddVertex('R');
    graph.AddVertex('S');
    graph.AddVertex('T');
    graph.AddVertex('U');
    graph.AddVertex('V');
    graph.AddVertex('W');
    graph.AddVertex('X');
    graph.AddVertex('Y');
    graph.AddVertex('Z');
    graph.AddEdge('A', 'B', 1);
    graph.AddEdge('A', 'C', 1);
    graph.AddEdge('A', 'D', 1);
    graph.AddEdge('A', 'E', 1);
    graph.AddEdge('A', 'F', 1);
    graph.AddEdge('A', 'G', 1);
    graph.AddEdge('A', 'H', 1);
    graph.AddEdge('A', 'I', 1);
    graph.AddEdge('A', 'J', 1);
    graph.AddEdge('A', 'K', 1);
    graph.AddEdge('A', 'L', 1);
    graph.AddEdge('A', 'M', 1);
    graph.AddEdge('B', 'C', 1);
    graph.AddEdge('B', 'D', 1);
    graph.AddEdge('B', 'E', 1);
    graph.AddEdge('B', 'F', 1);
    graph.AddEdge('B', 'G', 1);
    graph.AddEdge('B', 'H', 1);
    graph.AddEdge('B', 'I', 1);
    graph.AddEdge('B', 'J', 1);
    graph.AddEdge('B', 'K', 1);
    graph.AddEdge('B', 'L', 1);
    graph.AddEdge('B', 'M', 1);
    graph.AddEdge('B', 'N', 1);
    graph.AddEdge('B', 'O', 1);
    graph.AddEdge('B', 'P', 1);
    graph.AddEdge('B', 'Q', 1);
    graph.AddEdge('B', 'Z', 1);
    BreathFirstSearch(graph, 'A', 'Z');
}