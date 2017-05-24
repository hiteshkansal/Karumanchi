#include<iostream>
#include<limits.h>
using namespace std;

int buyleft, sellright,maxprofit;

int min1(int *arr, int a, int b)
{
    int mn=INT_MAX,in;
    for(int i=a; i<=b; i++)
    {
        if(arr[i]<mn)
        {
            mn = arr[i];
            in =i;
        }
    }
    return in;
}
int max1(int *arr, int a, int b)
{
    int mx=INT_MIN,in;
    for(int i=a; i<=b; i++)
    {
        if(arr[i]>mx)
        {
            mx = arr[i];
            in=i;
        }
    }
    return in;
}

int stock(int *a,int l,int r)
{
    int pleft, pright,minleft,maxright,profit;
    if(l+1==r)
    {
        int t = a[r]-a[l];
        if(t>maxprofit)
        {
            buyleft = l;
            sellright = r;
            maxprofit = t;
        }
        return t;
    }

    int mid = (l+r)/2;
    pleft = stock(a,l,mid);
    pright = stock(a,mid,r);

    minleft = min1(a,l,mid);
    maxright = max1(a,mid,r);
    profit = a[maxright]-a[minleft];
    if(pleft>max(pright,profit))
    {
        if(pleft>maxprofit)
            maxprofit = pleft;
        return pleft;
    }
    else if(pright>max(pleft,profit))
    {
        if(pright>maxprofit)
            maxprofit = pright;
        return pright;
    }
    else
    {
        if(profit>maxprofit)
        {
            maxprofit = profit;
            buyleft = minleft;
            sellright = maxright;
        }
        return profit;
    }
}

int main()
{
    int a[] = {1,2,3,5,0,3};
    int n = sizeof(a)/sizeof(a[0]);
    int p = stock(a,0,n-1);
    cout<<"Buy date index: "<<buyleft<<endl;
    cout<<"Sell date index: "<<sellright<<endl;
    cout<<"Profit: "<<p;
    return 0;
}
