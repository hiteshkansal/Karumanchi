#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    //int a[] = {2,5,8,10,11,13,16,17,18,21,24};
    int a[] = {1,2,3,4,5,13,14,15,16,17,18};
    int n = sizeof(a)/sizeof(a[0]);
    int i = n/2, count=0,j,k=5,l;
    j=i+1;
    l=i-1;
    while(count!=k)
    {
        if(abs(a[i]-a[l]) > abs(a[i]-a[j]))
        {
            cout<<a[j]<<" ";
            count++;
            j++;
        }
        else if(abs(a[i]-a[l]) < abs(a[i]-a[j]))
        {
            cout<<a[l]<<" ";
            count++;
            l--;
        }
        else
        {
            cout<<a[j]<<" ";
            count++;
            if(count==k)
                return 0;
            cout<<a[l]<<" ";
            count++;
            j++;
            l--;
        }
    }
    return 0;
}
