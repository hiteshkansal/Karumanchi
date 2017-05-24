#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int a[] = {-2,11,-4,13,-5,2};
   // int a[] = {1,-3,4,-2,-1,6};
    int maxsum= INT_MIN;
    const int n=sizeof(a)/sizeof(a[0]);
    int m[n]= {0};
    if(a[n-1]>0)
        m[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        m[i] = m[i+1]+a[i];
        if(m[i]>0)
            continue;
        else
            m[i]=0;
    }
      for(int i=0;i<n;i++)
        cout<<m[i]<<" ";
      cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(m[i]>maxsum)
            maxsum=m[i];
    }
    cout<<maxsum;
    return 0;
}

