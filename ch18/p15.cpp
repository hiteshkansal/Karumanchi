#include<iostream>
using namespace std;

int median(int *a, int n)
{
    if(n%2==0)
        return (a[n/2]+a[n/2-1])/2;
    else
        return a[n/2];
}
int findmedian(int *a,int *b, int n)
{
    if(n<1)
        return -1;
    if(n==1)
        return (a[0]+b[0])/2;
    if(n==2)
        return (max(a[0],b[0])+max(a[1],b[1]))/2;

    int mid1 = median(a,n);
    int mid2 = median(b,n);
    if(mid1==mid2)
        return a[mid1];

    else if (mid1<mid2)
    {
        if (n%2==0)
            return findmedian(a+n/2-1,b,n-n/2+1);
        else
            return findmedian(a+n/2,b,n-n/2);
    }

    else
    {
        if (n%2==0)
            return findmedian(a,b+n/2-1,n-n/2+1);
        else
            return findmedian(a,b+n/2,n-n/2);
    }
}
int main()
{
    int a[] = {2,4,5,7,8,10,13};
    int b[] = {1,3,6,10,11,13,15};
    cout<<findmedian(a,b,7);
    return 0;
}
