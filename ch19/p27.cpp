#include<iostream>
#include<algorithm>
using namespace std;

int halfsum(int a[], int n)
{
    int k=0;
    for(int i=0;i<n;i++)
        k+=a[i];
    int sum[k+1];
    for(int i=1;i<=k;i++)
        sum[i]=0;
    sum[0]=1;
    int r=0;
    cout<<"k: "<<k<<endl;
    for(int i=0;i<n;i++)
        for(int j=r;j>=0;j--)
        {
            if(sum[j])
                sum[j+a[i]]=1;
            r = min(k/2,r+a[i]);
        }

    for(int i=0;i<=k;i++)
        cout<<sum[i]<<" ";
    cout<<endl;
    return sum[k/2];
}

int main()
{
    int a[] = {4,6};
    int n = sizeof(a)/sizeof(a[0]);
    sort(a,a+n);
    if(halfsum(a,n))
        cout<<"yes!!";
    else
        cout<<"no!!";
    return 0;
}
