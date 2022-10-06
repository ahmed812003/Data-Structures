#include <iostream>
using namespace std;

const int MaxSize=(int)1e5;

struct stack{
    int top;
    int entry[MaxSize];
};

void Push(int value , stack &s){
    s.entry[s.top++]=value;
}
void Pop (int &value , stack &s){
    value=s.entry[--s.top];
}
bool StackEmpty(stack &s){
    return s.top==0;
}
bool StackFull (stack &s){
    return s.top==MaxSize;
}
void CreatStack (stack &s){
    s.top=0;
}
void StackTop(int &value , stack &s){
    value = s.entry[s.top-1];
}
int StackSize (stack &s){
    return s.top;
}
void ClearStack(stack &s){
    s.top=0;
}
void Display (stack &s){
    for(int i=s.top-1 ; i>=0 ; i--){
        cout<<s.entry[i]<<" ";
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
