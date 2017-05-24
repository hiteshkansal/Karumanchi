#include<iostream>
#include<string.h>

using namespace std;

int LP_substring(char a[], int n)
{
    int l[n][n];
    int mx=1;

    memset(l,0,sizeof(l));

    for(int i=0;i<n;i++)
        l[i][i] = 1;
    for(int k=2;k<=n;k++)
    {
        for(int i=0;i<n-k+1;i++)
        {
            int j = i+k-1;
            if(a[i] == a[j] && l[i+1][j-1])
            {
                l[i][j] = 1;
                mx =k;
            }
            else
                l[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<l[i][j]<<" ";
        cout<<endl;
    }
    return mx;
}

int main()
{
    char a[] = {'a','b','c','b','a','g'};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<LP_substring(a,n);
    return 0;
}
