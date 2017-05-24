#include<iostream>

using namespace std;

int main()
{
    int a[] = {5,2,15,9,10,3,16,6};
    int n = 8,temp;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
/*
    int a[] = {1,2,3,4,5,6,7,8};
    int n = 8,temp, flag =1,c=0;
    for(int i=n-1;i>=0 && flag;i--)
    {
        flag =0;
        for(int j=0;j<=i;j++)
        {
        c++;
            if(a[j]>a[j+1])
            {
                flag =1;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    cout<<c<<endl;
    */
    for(int i=0;i<n;i++)
       cout<<a[i]<<" ";
    return 0;
}
