#include <iostream>
using namespace std;

typedef struct node {
    int value;
    struct node* next;

} QueueNode;

typedef struct Queue {
    QueueNode* front;
    QueueNode* rear;
    int size;

} queue;

void CreatQueue (queue& q) {
    q.front = NULL;
    q.rear = NULL;
    q.size = 0;
}

void Push (int val , queue& q) {
    QueueNode* ptr = (QueueNode*)malloc(sizeof(QueueNode));
    ptr->value = val;
    ptr->next = NULL;
    if (!q.rear)
        q.front = ptr;
    else
        q.rear->next = ptr;
    q.rear = ptr;
    q.size++;
}

void Pop(int& value , queue& q) {
    QueueNode* ptr = q.front;
    q.front = ptr->next;
    free(ptr);
    if (!q.front)
        q.rear = NULL;
    q.size--;
}

void QueueFront(int& value , queue& q) {
    value = q.front->value;
}

bool QueueEmpty (queue& q) {
    return !q.size;
}

bool QueueFull (queue& q) {
    return 0;
}

int QueueSize (queue& q) {
    return q.size;
}

void QueueClear (queue& q) {
    while (q.front) {
        q.rear = q.front->next;
        free(q.front);
        q.front = q.rear;
    }
    q.size = 0;
}

void Disply (queue& q) {
    QueueNode* ptr = q.front;
    while (ptr) {
        cout << ptr->value << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

int main()
{
    queue q;
    CreatQueue(q);
    Push(1, q);
    Push(2, q);
    Push(3, q);
    Push(4, q);
    Push(5, q);
    Disply(q);
    int value;
    cout << QueueEmpty(q) << " " << QueueFull(q) << " " << QueueSize(q) << "\n";
    Pop(value, q);
    cout << value << "\n";
    Disply(q);
    QueueFront(value, q);
    cout << value << "\n";
    QueueClear(q);
    cout << QueueEmpty(q) << " " << QueueFull(q) << " " << QueueSize(q) << "\n";
    return 0;
}
