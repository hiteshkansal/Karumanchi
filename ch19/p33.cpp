#include<iostream>

using namespace std;

int game(int a[], int n)
{
    int v[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            v[i][j] = 0;
    for(int i=0;i<n;i++)
        v[i][i] = a[i];

    int i;
    for(int k=1;k<n;k++)
    {
        for(int j=k,i=0;j<n;j++,i++)
        {
            int t = min(v[i+1][j-1],v[i+2][j]);
            int k = min(v[i][j-2],v[i+1][j-1]);
            v[i][j] = max(t+a[i],k+a[j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return v[0][n-1];
}

int main()
{
    int a[] = {8,15,3,7};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<game(a,n);
    return 0;
}
