#include<iostream>
#include<string.h>

using namespace std;


int matrix(int a[][3], int r, int c)
{
    int l[r][c];
    memset(l,0,sizeof(l));

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0 && j==0)
                l[i][j] = a[i][j];
            else if(i==0 && j>0)
                l[i][j] = l[i][j-1]+a[i][j];
            else if(j==0 && i>0)
                l[i][j] = l[i-1][j]+a[i][j];
            else
                l[i][j]  = max(l[i-1][j],max(l[i][j-1],l[i-1][j-1]))+a[i][j];
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<l[i][j]<<" ";
        cout<<endl;
    }
    return l[r-1][c-1];
}

int main()
{
    const int r=3, c=3;
    int a[r][c] = {11,2,3,7,8,4,3,2,6};
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    cout<<matrix(a,r,c);
    return 0;
}

