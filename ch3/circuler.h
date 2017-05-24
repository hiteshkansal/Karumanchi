#ifndef CIRCULER_H_INCLUDED
#define CIRCULER_H_INCLUDED

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
    cin>>value;
    node * nw = (struct node *)malloc(sizeof(node));
    nw->data = value;
    nw->next = NULL;
    return nw;
}
node* llist(int m)
{
    node *ll,*p,*head;
    ll= create();
    head=ll;
    for(int i=0; i<m-1; i++)
    {
        p=ll;
        ll=create();
        p->next = ll;
    }
    ll->next = head;
    return head;
}

#endif // CIRCULER_H_INCLUDED
