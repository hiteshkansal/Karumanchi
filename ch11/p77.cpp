#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int a[] = {34,8,10,3,2,80,30,33,1};
    int maxd=-1,i,j, n=9;
    int *leftm = (int*)malloc(sizeof(int)*n);
    int *rightm = (int*)malloc(sizeof(int)*n);

    leftm[0] = a[0];
    rightm[n-1] = a[n-1];

    for(i=1;i<n;i++)
        leftm[i]= min(a[i],leftm[i-1]);
    for(i=n-2;i>=0;i--)
        rightm[i]= max(a[i],rightm[i+1]);

    i=0,j=0;
    while(j<n && i<n)
    {
        if(leftm[i]<rightm[j])
        {
            maxd = max(maxd, j-i);
            j++;
        }
        else
            i++;
    }
    cout<<maxd;
    return 0;
}
