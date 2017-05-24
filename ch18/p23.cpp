#include<iostream>

using namespace std;

void shuffle(string *a, int l, int r)
{
    if(l+1==r)
        return;

    int mid = (l+r)/2;
    int q = (l+mid+1)/2;
    int k=mid+1;
    for(int i=q;i<=mid;i++,k++)
        swap(a[i],a[k]);

    shuffle(a,l,mid);
    shuffle(a,mid+1,r);
}

int main()
{
    string a[] = {"a1","a2","a3","a4","b1","b2","b3","b4"};  // when n=2^i where i=0,1,2,....
    int n = sizeof(a)/sizeof(a[0]);
    shuffle(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
