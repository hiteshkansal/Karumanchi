#include<iostream>

using namespace std;
/*
bool issubset(int a[], int n, int sum)
{
    sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    if(sum%2==1)
        return false;
    if(!sum)
        return true;
    if(n==0 && sum!=0)
        return false;
    if(a[n-1]>sum)
        return issubset(a,n-1,sum);
    return issubset(a,n-1,sum) || issubset(a,n-1,sum-a[n-1]);
}
*/

bool issubset(int a[], int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    if(sum%2==1)
        return false;
    if(!sum)
        return true;
    if(n==0 && sum!=0)
        return false;

    for(int i=0;i<n;i++)
    {
        if(a[i]>sum/2)
            return false;
    }
    int table[sum/2+1][n+1];

    for(int i=0;i<=n;i++)
        table[0][i] = 1;
    for(int i=1;i<=sum/2;i++)
        table[i][0] = 0;

    for(int i=1;i<=sum/2;i++)
        for(int j=1;j<=n;j++)
        {
            table[i][j] = table[i][j-1];
            if(i>=a[j-1])
                table[i][j] = table[i][j] || table[i-a[j-1]][j-1];
        }

    for(int i=0;i<=sum/2;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
        return table[sum/2][n];
}

 //BY USING HALF SUM METHOD PROBLEM 27
  /*
bool issubset(int a[], int n)
{
    int k=0;
    for(int i=0; i<n; i++)
        k+=a[i];
    if(k%2==1)
        return false;
    if(!k)
        return true;
    if(n==0 && k!=0)
        return false;

    for(int i=0;i<n;i++)
    {
        if(a[i]>k/2)
            return false;
    }
    int sum[k+1];
    for(int i=1; i<=k; i++)
        sum[i]=0;
    sum[0]=1;
    int r=0;
    cout<<"k: "<<k<<endl;
    for(int i=0; i<n; i++)
        for(int j=r; j>=0; j--)
        {
            if(sum[j])
                sum[j+a[i]]=1;
            r = min(k/2,r+a[i]);
        }

    for(int i=0; i<=k; i++)
        cout<<sum[i]<<" ";
    cout<<endl;
    return sum[k/2];
}
*/
int main()
{
    int a[] = {3, 1, 1, 1, 2, 2};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<issubset(a,n);
    return 0;
}
