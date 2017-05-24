#include<iostream>
#include<stdlib.h>

using namespace std;
int *a,top=-1,sz=1;

void doubles()
{
    sz*=2;
    a=(int*)realloc(a,sz);
}

void push(int v)
{
    if(top==sz-1)
        doubles();
    ++top;
    a[top]=v;
}

void pop()
{
    if(top==-1)
    {
        cout<<"Under flow."<<endl;
        return;
    }
    cout<<"popped element is: "<<a[top]<<endl;
    top--;
}

void print()
{
    cout<<"Current content of stack is: ";
    for(int i=top; i>=0; i--)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    a=(int*)malloc(sizeof(int));
    push(1);
//    cout<<"size is: "<<sz<<endl;
    push(2);
//    cout<<"size is: "<<sz<<endl;
    push(3);
//    cout<<"size is: "<<sz<<endl;
    print();
    pop();
    print();
    pop();
    print();
    pop();
    pop();
    return 0;
}
