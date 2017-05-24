#include<iostream>

using namespace std;

int main()
{
    int a[]={1,2,3,4,6,7,8,5};
    int n=9,i,x=0,y=0;
    for(i=0;i<n-1;i++)
        x^=a[i];
    for(i=0;i<=n;i++)
        y^=i;
    cout<<(x^y);
    return 0;
}
