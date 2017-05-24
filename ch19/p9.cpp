#include<iostream>
#include<limits.h>

using namespace std;

int main()
{
    int a[] = {-2,11,-4,13,-5,2};
    // int a[] = {1,-3,4,-2,-1,6};
    const int n=sizeof(a)/sizeof(a[0]);
    int m[n];
    m[0] = a[0];
    m[1] = max(a[0],a[1]);

    for(int i=2; i<n; i++)
        m[i] = max(m[i-1],m[i-2]+a[i]);

    for(int i=0; i<n; i++)
        cout<<m[i]<<" ";
    cout<<endl;
    cout<<m[n-1];
    return 0;
}
