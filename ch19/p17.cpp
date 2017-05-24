#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

int maxinvalue(int m[], int w[], int v[], int j)
{
    int sum = 0;
    for(int i=0; w[i]<=j; i++)
    {
        int k = m[j-w[i]] + v[i];
        if(k>sum)
            sum = k;
    }
//    cout<<sum<<endl;
    return sum;
}

int intknapsack(int w[], int v[],int n)
{
    const int c = 6;
    int m[c+1];
    for(int j=0; j<=c; j++)
        m[j]=0;
    int j;
    for(j=1; j<=c; j++)
    {
        if(j<w[0])
            m[j] = m[j-1];
        else
            m[j] = max(m[j-1],maxinvalue(m,w,v,j));

    }
    for(int j=0; j<=c; j++)
        cout<<m[j]<<" ";
    cout<<endl;

    return m[c];
}
int main()
{
    int w[] = {2,4,4,5};
    int v[] = {3,4,5,6};
    int n=sizeof(w)/sizeof(w[0]);
    multimap<int,int> m;
    for(int i=0; i<n; i++)
        m.insert( {w[i],v[i]});
    auto it = m.begin();
    for(int i=0; it!=m.end(); it++)
    {
        w[i] = it->first;
        v[i] = it->second;
        i++;
    }
    cout<<intknapsack(w,v,n);
    return 0;
}
