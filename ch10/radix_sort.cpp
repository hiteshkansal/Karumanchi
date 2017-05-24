#include<iostream>

using namespace std;

int main()
{
    int a[]= {123,231,222,154,14,43};
    int *temp = a;
    const int n=sizeof(a)/sizeof(a[0]);
    int m=a[0],h=1,b[n] = {0};
    for(int i = 1; i < n; i++)
    {
        if (a[i] > m)
            m = a[i];
    }
    int i,j;
    const int k=10;

    while(m/h)
    {
        int c[k] = {0};

        for(j=0; j<n; j++)
            c[(temp[j]/h)%10]++;

        for(i=1; i<k; i++)
            c[i] = c[i]+c[i-1];

        for(j=n-1; j>=0; j--)
        {
            b[c[(temp[j]/h)%10]-1] = temp[j];
            c[(temp[j]/h)%10]--;
        }

        for(int i=0; i<n; i++)
            temp[i] = b[i];
        h*=10;
    }
   for(int i=0;i<n;i++)
          cout<<temp[i]<<" ";
    return 0;
}
