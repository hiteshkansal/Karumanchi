#include<iostream>
using namespace std;

int main()
{
    int p[]={-1,0,1,6,6,0,0,2,7};
    int maxm=-1, cur=-1,i,j,n;
    n=sizeof(p)/sizeof(p[0]);
    for(i=0;i<n;i++)
    {
        cur=0;
        for(j=i;p[j]!=-1;j=p[j])
            cur++;

        if(cur>maxm)
        maxm=cur;
    }
    cout<<maxm;
    return 0;
}
