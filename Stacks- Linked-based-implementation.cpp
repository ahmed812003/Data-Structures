#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node{
    int value;
    struct node * next;
}StackNode;

typedef struct Stack{
    StackNode* top;
    int size;
}stack;

// time=o(1)
void CreatStack (stack &s){
    s.top=NULL;
    s.size=0;    
}

// time=o(1)
void Push(int val , stack &s){
    StackNode* ptr=(StackNode*)malloc(sizeof(StackNode));
    ptr->value=val;
    ptr->next=s.top;
    s.top=ptr;
    s.size++;
}

// time=o(1)
void Pop (int &val , stack &s){
    StackNode* ptr;
    val=s.top->value;
    ptr=s.top;
    s.top=s.top->next;
    free(ptr);
    s.size--;
}

// time=o(1)
bool StackEmpty(stack &s){
    return !s.top;
}

// time=o(1)
bool StackFull (stack &s){
    return 0;
}

// time=o(1)
void StackTop(int &val , stack &s){
    val=s.top->value;
}

// time=o(1)
int StackSize (stack &s){
    return s.size;
}

// time=o(stack size)
void ClearStack(stack &s){
    StackNode* ptr=s.top;
    while(ptr){
        ptr=s.top->next;
        free(s.top);
        s.top=ptr;
    }
    s.size=0;
}

// time : o(stack.size)
void Display (stack &s){
    StackNode* ptr=s.top;
    while(ptr){
        cout<<ptr->value<<" ";
        ptr=ptr->next;
    }
    cout<<"\n";
}

int main(){
    stack s;
    CreatStack(s);
    
    Push(10,s);
    Push(11,s);
    Push(12,s);
    Push(13,s);
    Push(14,s);
    
    Display(s);
    
    cout<<StackFull(s)<<" "<<StackEmpty(s)<<" "<<StackSize(s)<<"\n";
    
    int x=-1;
    
    if(!StackEmpty(s))
        Pop(x,s);
    
    cout<<x<<" "<<StackSize(s)<<"\n";
    
    Display(s);
    
    StackTop(x,s);
    
    cout<<x<<"\n";
    
    ClearStack(s);
    
    cout<<StackSize(s)<<"\n";

    return 0;
}