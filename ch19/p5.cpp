#include<iostream>
#include<limits.h>
using namespace std;

int main()
{
    int a[] = {-2,11,-4,13,-5,6,-1};
    int cursum,maxsum= INT_MIN, n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++)
    {
        cursum=0;
        for(int j=i;j<n;j++)
        {
            cursum+=a[j];
            if(cursum>maxsum)
                maxsum =cursum;
        }
    }
    cout<<maxsum;
    return 0;
}
