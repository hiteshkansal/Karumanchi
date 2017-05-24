#include<iostream>
#include<deque>

using namespace std;

int main()
{
    deque<int> dq;
    int i;
    int a[]={1,3,-1,-3,5,3,6,7};
    int w=3, n=sizeof(a)/sizeof(int);
    int b[n-w+1];
    for(i=0;i<w;i++)
    {
        while(!dq.empty() && a[i]>=a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }

    for(;i<n;i++)
    {
        b[i-w] = a[dq.front()];
        while(!dq.empty() && a[i]>=a[dq.back()])
            dq.pop_back();
        while(!dq.empty() && dq.front()<=i-w)
            dq.pop_front();
        dq.push_back(i);
    }
    b[n-w] = a[dq.front()];

    for(int i=0;i<=n-w;i++)
        cout<<b[i]<<" ";
    return 0;
}
