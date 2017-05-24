#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct binaryheap
{
    int *ar;
    int cnt;
    int capacity;
    int heap_type;
} heap;

heap* create(int cp,int typ)
{
    heap* h = (heap*)malloc(sizeof(heap));
    if(!h)
        return NULL;
    h->heap_type = typ;
    h->cnt = 0;
    h->capacity = cp;
    h->ar = (int*)malloc(h->capacity*sizeof(int));
    if(!h->ar)
        return NULL;
    return h;
}
int parent(heap* h, int i)
{
    if(i<=0||i>h->cnt)
        return -1;
    return (i-1)/2;
}
int left(heap *h, int i)
{
    int lft = 2*i+1;
    if(lft>=h->cnt)
        return -1;

    return lft;
}

int right(heap *h, int i)
{
    int rght = 2*i+2;
    if(rght>=h->cnt)
        return -1;
    return rght;
}

int getmax(heap*h)
{
    if(h->cnt == 0)
        return -1;
    return h->ar[0];
}

int maxchld(heap *h,int a, int b)
{
    if(a<0)
        return b;
    if(b<0)
        return a;
    if(h->ar[a] > h->ar[b])
        return a;
    else
        return b;
}
heap* perlocate(heap* h, int i)
{
    if(i<0)
        return NULL;
    int l,r,mx,temp;
    l=left(h,i);
    r=right(h,i);
    mx = maxchld(h,l,r);
    if(mx!=-1 && h->ar[mx] > h->ar[i])
    {
        temp = h->ar[i];
        h->ar[i] = h->ar[mx];
        h->ar[mx] = temp;
    }
    perlocate(h,mx);
    return h;
}

int deletemax(heap *h)
{
    int data;
    if(h->cnt ==0)
        return -1;
    data=h->ar[0];
    h->ar[0]=h->ar[h->cnt-1];
    h->cnt--;
    h = perlocate(h,0);
    return data;
}

heap* rsize(heap *h)
{
    h->capacity*=2;
    h->ar = (int*)realloc(h->ar, h->capacity*sizeof(int));
    return h;
}

heap* insrt(heap*h, int data)
{
    int i;
    if(h->cnt ==h->capacity)
        rsize(h);

    i=h->cnt;
    h->cnt++;
    while(i>0 && data>h->ar[(i-1)/2])
    {
        h->ar[i] = h->ar[(i-1)/2];
        i=(i-1)/2;
    }
    h->ar[i] = data;
    return h;
}

void destroy(heap *h)
{
    if(!h)
        return;
    free(h->ar);
    free(h);
    h = NULL;
}

#endif // HEAP_H_INCLUDED
