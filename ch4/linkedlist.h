#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

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
node* llist()
{
    node *ll,*p,*head;
    cout<<"how many node u want to create: ";
    cin>>m;
    ll= create();
    head=ll;
    for(int i=0; i<m-1; i++)
    {
        p=ll;
        ll=create();
        p->next = ll;
    }
    ll->next = NULL;
    return head;
}
void printlist(node *head)
{
    if(!head){
        cout<<"No element";
        return;
    }
    cout<<"Element of list: ";
    while(head!=NULL)
        {
            cout<<head->data<<" ";
            head = head->next;
        }
}
#endif // LINKEDLIST_H_INCLUDED
