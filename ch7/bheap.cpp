#include "heap.h"
/*int main()
{
    heap* h= create(7,1);   //tp=1-> max heap
    h=insrt(h,4);
    h=insrt(h,1);
    h=insrt(h,10);
    h=insrt(h,15);
    h=insrt(h,16);
    h=insrt(h,7);
    h=insrt(h,24);
    h=insrt(h,11);
    h=insrt(h,12);
    h=insrt(h,2);
    h=insrt(h,3);

    deletemax(h);
    for(int i=0; i<h->cnt; i++)
        cout<<h->ar[i]<<" ";
}
*/

heap* buildheap(heap* h, int a[],int n)
{
    if(!h)
        return NULL;
    while(n>h->capacity)
        rsize(h);
    for(int i=0;i<n;i++)
        h->ar[i] = a[i];

    h->cnt = n;

    for(int i=(n-1)/2;i>=0;i--)
       h = perlocate(h,i);

    return h;
}
/*
int main()
{
    heap * h = create(10,1);
    int a[] = {6,2,8,11,4,17,9,10};
    int n=sizeof(a)/sizeof(int);
    h= buildheap(h,a,n);

    for(int i=0; i<h->cnt; i++)
        cout<<h->ar[i]<<" ";
    cout<<endl;
    // heap sort
    while(h->cnt!=0)
        cout<<deletemax(h)<<" ";
    return 0;
}
*/
