#include<iostream>

using namespace std;

int main()
{
    int a[] = {3,5,6,1,2,6,2,4};
    int n=8,i,j,k=7;
    int b[n],c[k];

    for(i=0;i<k;i++)
        c[i]=0;

    for(i=0;i<n;i++)
        b[i]=0;

    for(j=0;j<n;j++)
        c[a[j]]++;

    for(i=1;i<k;i++)
        c[i] = c[i]+c[i-1];

    for(j=n-1;j>=0;j--)
    {
        b[c[a[j]]-1] = a[j];
        c[a[j]]--;
    }

    for(i=0;i<n;i++)
        cout<<b[i]<<" ";
    return 0;
}
