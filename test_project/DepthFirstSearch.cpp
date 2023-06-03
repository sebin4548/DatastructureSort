#include<iostream>
#include<stack>
#include<queue>
#include<list>
using namespace std;

template<class VertexType>
class QueType{
public:
    void Push(VertexType vertex){
        que.push(vertex);
    }
    void Dequeue(VertexType &vertex){
        
        vertex = que.front();
        que.pop();
    }
    bool IsEmpty(){
        return que.empty();
    }
    
    queue<VertexType> que;
};
template<class VertexType>
class StackType{
public:
    void Push(VertexType vertex){
        stack_.push(vertex);
    }
    void Pop(VertexType &vertex){
        
        vertex = stack_.top();
        stack_.pop();
    }
    bool IsEmpty(){
        return stack_.empty();
    }
    stack<VertexType> stack_;
    
};


template<class VertexType>
class Way{
public:
    VertexType from;
    VertexType to;

    Way(VertexType from, VertexType to) : from(from), to(to){
        
    }
};


template<class VertexType>
class GraphType{
public:
    void ClearMarks(){
        visited.empty();
    }
    bool IsMarked(VertexType vertex){
        for(VertexType c : visited){
            if(c == vertex) return true;
        }
        return false;
//        list<VertexType>::iterator it;
//        for(it = visited.begin(); it != visited.end; it++;){
//            if(*li ==vertex) return true;
//        }
//        return false;
    }
    void GetToVertices(VertexType vertex, QueType<VertexType>& vertexQ){
//        list<Way<VertexType>>::iterator it_begin = way.begin();
//        list<Way<VertexType>>::iterator it_end = way.begin();
//        for(; it_begin != it_end; ++it_begin){
//            if(*it_begin.from == vertex){
//                vertexQ.Push(*it_begin.end);
//            }
//        }
        for(Way<VertexType> c : way){
            if(c.from == vertex) vertexQ.Push(c.to);
        }
    }
    void MarkVertex(VertexType vertex){
        if(!IsMarked(vertex)){
            visited.push_back(vertex);
//            visited.insert(vertex);
        }
    }
    void add(VertexType from, VertexType to){
        way.push_back(Way(from, to));
    }
    list<VertexType> visited;
    list<Way<VertexType>> way;
};

template<class VertexType>
void DepthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex){
    StackType<VertexType> stack;
    QueType<VertexType> vertexQ;
    
    bool found = false;
    VertexType vertex;
    VertexType item;
    
    graph.ClearMarks();
    
    stack.Push(startVertex);
    do{
        stack.Pop(vertex);
        
        if(vertex == endVertex){
            cout<<vertex;
            cout<<"found";
            found = true;
        } else{
            if(!graph.IsMarked(vertex)){
                graph.MarkVertex(vertex);
//                cout<<vertex;
                graph.GetToVertices(vertex, vertexQ);
                
                while(!vertexQ.IsEmpty()){
                    vertexQ.Dequeue(item);
                    if(!graph.IsMarked(item))
                        stack.Push(item);
                }
            }
        }
    }while(!stack.IsEmpty()&&!found);
    
    if(!found){
        cout<<"Path not found"<<endl;
    }
}
