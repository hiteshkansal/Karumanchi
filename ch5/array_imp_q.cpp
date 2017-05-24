#include"queue.h"
extern int n;

int main()
{
    cout<<"queue size: ";
    cin>>n;
    int a[n],i;

    for(i=0; i<n; i++)
        a[i]=0;
    enq(a,1);
    enq(a,2);
    enq(a,3);
    deq(a);
    deq(a);
    display(a);
    enq(a,4);
    enq(a,5);
    enq(a,6);
    display(a);
    deq(a);
    deq(a);
    display(a);
    deq(a);
    deq(a);
    display(a);
    return 0;
}
