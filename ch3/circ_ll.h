#ifndef CIRC_LL_H_INCLUDED
#define CIRC_LL_H_INCLUDED

#include<iostream>
#include<stdlib.h>
int m;
using namespace std;
typedef struct node
{
    int data;
    struct node* next;
}node;



node* create()
{
    int value;
    cout<<"Enter value:";
    cin>>value;
    node * nw = (struct node *)malloc(sizeof(node));
    nw->data = value;
    nw->next = NULL;
    return nw;
}
node* llist()
{
    node *ll,*temp,*p,*head;
    cout<<"how many node u want to create. minimum 2: ";
    cin>>m;

    temp = create();
    ll= create();
    head=ll;
    temp->next = head;
    for(int i=0; i<m-2; i++)
    {
        p=ll;
        ll=create();
        p->next = ll;
    }
    ll->next = head;
    head=temp;
    return head;
}


#endif // CIRC_LL_H_INCLUDED
