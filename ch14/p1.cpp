#include<iostream>
#include<stdlib.h>
#define LOAD_FACTOR 5
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct hashnode{
    int bcnt;
    node* nw;
}hnode;

typedef struct hashtable{
    int hsize;
    int cnt;
    hnode* table;
}table;

size_t hashh(table *h, int data)
{
    if(data>0)
        return (data%(h->hsize));

    return -1;
}

table* create(int sz)
{
    table *h;
    h= (table*)malloc(sizeof(table));
    if(!h)
        return NULL;
    h->hsize = sz;///LOAD_FACTOR;
    h->cnt = 0;
    h->table = (hnode*)malloc(sizeof(hnode)*(h->hsize));

    if(!h->table)
        return NULL;

    for(int i=0;i<(h->hsize);i++)
    {
        ((h->table)+i)->nw = NULL;
        ((h->table)+i)->bcnt = 0;
    }
    return h;
}

int hsearch(table *h, int data)
{
    int i = hashh(h,data);
    node *temp;
    temp = ((h->table)+i)->nw;
    while(temp)
    {
        if(temp->data == data)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int hinsert(table* h, int data)
{
    struct node* newnode;
    if(hsearch(h,data))
        return 0;
    int index = hashh(h,data);
    newnode = (node*)malloc(sizeof(node));
    if(!newnode)
        return -1;
    newnode->data = data;
    newnode->next = NULL;
    node *temp ;
    temp = ((h->table)+index)->nw;
    if(temp==NULL)
        (h->table+index)->nw = newnode;
    else
    {
        while(temp->next)
            temp = temp->next;
        temp->next = newnode;
    }

    h->cnt++;
    ((h->table)+index)->bcnt++;
    cout<<data<<" inserted."<<endl;
    if((h->cnt/h->hsize)> LOAD_FACTOR)
        rehash(h);
    return 0;
}
int main()
{
    table *h = create(10);
    hinsert(h,5);
    hsearch(h,5);
    hinsert(h,16);
    hsearch(h,1);
    hinsert(h,4);
    hsearch(h,4);
    hinsert(h,15);

    cout<<((h->table+5))->bcnt;
    //hsearch(h,15);
    return 0;
}
