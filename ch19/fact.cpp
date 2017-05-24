#include<iostream>
using namespace std;

int fact[50]={0};
int facto(int n)
{
    fact[0] = fact[1] = 1;
    if(fact[n]!=0)
        return fact[n];
    else
        return fact[n] = n*facto(n-1);
}
int main()
{
    cout<<facto(12);
    return 0;
}
