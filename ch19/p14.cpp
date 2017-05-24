#include<iostream>
using namespace std;

int C[100];
int catalan(int n)
{
    if(n==0)
        return 1;
    if(C[n]!=1)
        return C[n];
    C[n] =0;
    for(int i=1;i<=n;i++)
        C[n] += catalan(i-1)*catalan(n-i);
    return C[n];
}

int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    for(int i=0;i<100;i++)
        C[i] = 1;

    cout<<catalan(n);
    return 0;
}
