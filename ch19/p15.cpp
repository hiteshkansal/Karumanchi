#include<iostream>
#include<limits.h>
using namespace std;

int matrix(int p[], int n)
{
    int m[n][n], s[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        m[i][j] =0;

    for(int l=2;l<n;l++)
    {
        for(int i=1;i<n-l+1;i++)
        {
            int j=i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i;k<j;k++)
            {
                int cost = m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(cost<m[i][j])
                {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
  /*  for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<m[i][j]<<" ";
            cout<<endl;
    }
*/
    return m[1][n-1];
}

int main()
{
    int p[] = {3,10,2,3};
    int n = sizeof(p)/sizeof(p[0]);
    cout<<matrix(p,n);
    return 0;
}
