#include <iostream>
using namespace std;
const int MaxSize=100000;
typedef struct Queue{
    int front;
    int rear;
    int size;
    int entry[MaxSize];

}queue;

void CreatQueue (queue& q){
    q.front=0;
    q.rear=-1;
    q.size=0;
}

void Push (int value , queue& q){
    q.rear=(q.rear+1)%MaxSize;
    q.entry[q.rear]=value;
    q.size++;
}

void Pop(int& value , queue& q){
    value=q.entry[q.front];
    q.front=(++q.front)%MaxSize;
    q.size--;
}

void QueueFront(int& value , queue& q){
    value=q.entry[q.front];
}

bool QueueEmpty (queue& q){
    return !q.size;
}

bool QueueFull (queue& q){
    return q.size==MaxSize;
}

int QueueSize (queue& q){
    return q.size;
}

void QueueClear (queue& q){
    q.front=0;
    q.rear=-1;
    q.size=0;
}

void Disply (queue& q){
    int pos=q.front;
    for(int i=0 ; i<q.size ; i++){
        cout<<q.entry[pos]<<" ";
        pos=(++pos)%MaxSize;
    }
    cout<<"\n";
}

int main()
{
    queue q;
    CreatQueue(q);
    Push(1,q);
    Push(2,q);
    Push(3,q);
    Push(4,q);
    Push(5,q);
    Disply(q);    
    int value;
    cout<<QueueEmpty(q)<<" "<<QueueFull(q)<<" "<<QueueSize(q)<<"\n";
    Pop(value,q);
    cout<<value<<"\n";
    Disply(q);
    QueueFront(value,q);
    cout<<value<<"\n";
    QueueClear(q);
    cout<<QueueEmpty(q)<<" "<<QueueFull(q)<<" "<<QueueSize(q)<<"\n";
    return 0;
}