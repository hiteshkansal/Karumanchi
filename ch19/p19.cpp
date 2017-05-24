#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

int mininvalue(int m[], int w[], int j)
{
    int sum = INT_MAX;
    for(int i=0; w[i]<=j; i++)
    {
        int k = m[j-w[i]];
        if(k<sum)
            sum = k;
    }
//    cout<<sum<<endl;
    return sum;
}

int coinchange(int w[],int n)//, const int d)
{
    const int c = 12;
    int m[c+1];
    for(int j=0; j<=c; j++)
        m[j]=0;
    int j;
    for(j=1; j<=c; j++)
    {
        if(j<w[0])
            m[j] = m[j-1];
        else
            m[j] = mininvalue(m,w,j)+1;
    }
    for(int j=0; j<=c; j++)
        cout<<m[j]<<" ";
    cout<<endl;

    return m[c];
}
int main()
{
    int w[] = {1,2,4,3};
    //const int c = 10;
    int n=sizeof(w)/sizeof(w[0]);
    sort(w,w+n);
    cout<<coinchange(w,n);
    return 0;
}
