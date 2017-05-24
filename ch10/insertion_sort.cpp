#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
using namespace std;

int main()
{
    vector<int> a;
    srand(time(0));
    int r,i,j,n=7;
    for(int i=0;i<n;i++)
    {
        r=rand()%20+1;
        a.push_back(r);
    }
    for(i=1;i<n;i++)
    {
        j=i;
        r = a[i];
        while(j>0 && a[j-1]>r)
        {
                a[j] = a[j-1];
                j--;
        }
        a[j] =r;
    }
    vector<int>::iterator it;
    it = a.begin();
    while(it!=a.end())
    {
        cout<<*it<<" ";
        it++;
    }
    return 0;
}
