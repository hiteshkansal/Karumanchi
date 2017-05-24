#include<iostream>
#include<stdlib.h>

using namespace std;

int LIS(int a[], int n)
{
    int l[n],max=0;
    for(int i=0; i<n; i++)
        l[i]= 1;

    for(int i=0; i<n; i++)
        for(int j=0; j<i; j++)
        {
            if(a[i]>a[j] && l[i]<l[j]+1)
                l[i]=l[j]+1;
        }
    for(int i=0; i<n; i++)
    {
        if(l[i]>max)
            max = l[i];
    }
    for(int i=0; i<n; i++)
        cout<<l[i]<<" ";
    cout<<endl;

    return max;
}

int main()
{
    //int a[] = {5,6,2,3,4,1,9,9,8,9,5};
    int a[] = {2,4,1,5,3};
    const int n = sizeof(a)/sizeof(a[0]);
    cout<<LIS(a,n);
    return 0;
}
