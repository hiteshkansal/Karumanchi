#include<iostream>

using namespace std;

int sz;
void k_arr(int a[],int n, int k)
{
    if(n<1)
    {
        static int c =1;
        cout<<c<<": ";
        for(int i=0;i<sz;i++)
            cout<<a[i];
        cout<<endl;
        c++;
    }
    else
    {
        for(int j=0;j<k;j++)
        {
            a[n-1] = j;
            k_arr(a,n-1,k);
        }
    }
}

int main()
{
    cin>>sz;
    int *a = new int[sz];
    k_arr(a,sz,4);
    return 0;
}
