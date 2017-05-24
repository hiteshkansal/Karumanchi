#include<iostream>
#include<string.h>

using namespace std;

void max_matrix(int a[][4], int m, int n)
{
    int l[m][n];

    for(int i=0;i<m;i++)
        l[i][0] = a[i][0];
    for(int i=0;i<n;i++)
        l[0][i] = a[0][i];

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(a[i][j])
                 l[i][j] = min(min(l[i-1][j],l[i][j-1]),l[i-1][j-1])+1;
            else
                l[i][j] = 0;
        }
    }
    cout<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<l[i][j]<<" ";
        cout<<endl;
    }

    int mx = l[0][0], mx_i=0,mx_j=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(l[i][j]>mx)
            {
                mx = l[i][j];
                mx_i = i;
                mx_j = j;
            }
        }
    }

    for(int i=mx_i;i>mx_i-mx;i--)
    {
        for(int j=mx_j;j>mx_j-mx;j--)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }

}

int main()
{
    const int m=4, n=4;
    int a[m][n] = {1,0,1,0,0,1,0,0,1,1,1,0,1,1,1,1};
  //  int a[m][n] = {0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    max_matrix(a,m,n);
    return 0;
}
