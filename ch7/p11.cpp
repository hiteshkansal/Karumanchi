#include"minheap.h"
#include"bheap.cpp"

heap* kthvalue(heap *h,int i ,int k)
{
    int elm  = h->ar[i];
     int l,r;
/*    while(elm < k)
    {
        elm = getmin(h);
        if(elm ==k)
            break;
        cout<<elm<<" ";
        deletemin(h);
    }
    */
    if(elm < k)
    {
        cout<<elm<<" ";
        l = left(h,i);
        r = right(h,i);
        kthvalue(h,l,k);
        kthvalue(h,r,k);
    }
    return h;
}

int main()
{
    heap * h = create(10,0);
    int a[] = {6,2,8,11,4,17,9,10,7};
    int n=sizeof(a)/sizeof(int);
    h= buildheap(h,a,n);
    h = kthvalue(h,0,10);
    cout<<endl;
    for(int i=0; i<h->cnt; i++)
        cout<<h->ar[i]<<" ";
    return 0;
}
