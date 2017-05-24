#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int a[] = {5,2,1,2,3,2};
    int b[6], n=6, flag[6] ={0};

    for(int i=0; i<6; i++)
        b[i] = INT_MIN;

    for(int i=0; i<n; i++)
    {
        if(b[a[i]] >= 0 && !flag[a[i]])
        {
            flag[a[i]] =1;
            b[a[i]] = -b[a[i]];
        }

        else if(b[a[i]]<0 && !flag[a[i]])
            b[a[i]] = i;
    }
    int mx =INT_MIN;
//    for(int i=0; i<6; i++)
    //      cout<<b[i]<<" ";

    for(int i=0; i<6; i++)
    {

        if(mx < b[i] && b[i]<0)
            mx = b[i];
    }
    cout<<a[abs(mx)];
    return 0;
}
