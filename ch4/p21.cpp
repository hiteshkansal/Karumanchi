#include<iostream>
#include<stack>
#include "linkedlist.h"
using namespace std;

int main()
{
    node *l1 = llist();
    node *l2 = llist();
    node *f1 = llist();
    node *p=l1,*q=l2;
    while(p->next!=NULL){
        p=p->next;
    }
    while(q->next!=NULL){
        q=q->next;
    }
    p->next = f1;
    q->next = f1;

    stack<node *> st1,st2;
    while(l1!=NULL)
    {
        st1.push(l1);
        l1=l1->next;
    }
    while(l2!=NULL)
    {
        st2.push(l2);
        l2=l2->next;
    }

    node *temp;
    while(st1.top() == st2.top())
    {
        temp = st1.top();
        st1.pop();
        st2.pop();
    }
    cout<<"Merging point "<<temp<<" and Value is: "<<temp->data;
    return 0;
}
