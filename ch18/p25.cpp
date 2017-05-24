#include<iostream>

using namespace std;

int maxcontseq(int *a,int l,int r)
{
    int maxleftbrdr =0, maxrightbrdr =0,leftsm=0,rightsm=0;
    int mid = (l+r)/2;
    if(l==r)
        return a[l]>0?a[l]:0;
    int mxleft = maxcontseq(a,l,mid);
    int mxright = maxcontseq(a,mid+1,r);
    for(int i=mid;i>=l;i--)
    {
        leftsm += a[i];
        if(leftsm>maxleftbrdr)
            maxleftbrdr = leftsm;
    }

    for(int i=mid+1;i<=r;i++)
    {
        rightsm += a[i];
        if(rightsm>maxrightbrdr)
            maxrightbrdr = rightsm;
    }
    return max(max(mxleft,mxright),maxrightbrdr+maxleftbrdr);
}
int main()
{
    int a[] = {-2,11,-4,13,-5,2};
//    int a[] = {1,-3,4,-2,-1,6};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<"Max sum is: "<<maxcontseq(a,0,n-1);
    return 0;
}
