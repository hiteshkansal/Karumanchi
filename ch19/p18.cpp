#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

int intknapsack(int w[], int v[],int n)
{
    const int c = 5;
    int m[n+1][c+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(i==0 || j==0)
                m[i][j]=0;
            else
            {
                if(j<w[i-1])
                    m[i][j] = m[i-1][j];
                else
                    m[i][j] = max(m[i-1][j],(m[i-1][j-w[i-1]])+v[i-1]);
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    return m[i-1][j-1];
}
int main()
{
    int w[] = {2,3,4,5};
    int v[] = {3,4,5,6};
    int n=sizeof(w)/sizeof(w[0]);
    multimap<int,int> m;
    for(int i=0;i<n;i++)
        m.insert({w[i],v[i]});
    auto it = m.begin();
    for(int i=0;it!=m.end();it++)
    {
        w[i] = it->first;
        v[i] = it->second;
        i++;
    }
      cout<<intknapsack(w,v,n);
    return 0;
}
