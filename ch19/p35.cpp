#include<iostream>
#include<string.h>
using namespace std;

int LP_subseq(int a[], int n)
{
    int j;
    int l[n][n];

    memset(l,0,sizeof(l));
    for(int i=0;i<n;i++)
        l[i][i] = 1;

    for(int k=2;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            j=i+k-1;
            if(a[i] == a[j])
                l[i][j] = l[i+1][j-1] + 2;
            else
                l[i][j] = max(l[i+1][j],l[i][j-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<l[i][j]<<" ";
        cout<<endl;
    }
    return l[0][n-1];
}

int main()
{
    int a[] = {1,1,1,7,5,19,16};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<LP_subseq(a,n);
    return 0;
}
