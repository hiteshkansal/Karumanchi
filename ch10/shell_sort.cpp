#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
using namespace std;

int main()
{
    vector<int> a;
    srand(time(0));
    int r,i,j,n=10,h;
    for(int i=0; i<n; i++)
    {
        r=rand()%50+1;
        a.push_back(r);
    }

    for(h=n/2; h>0; h/=2)
    {
        for(i=h; i<n; i++)
        {
            j=i;
            r = a[i];
            while(j>=h && a[j-h]>r)
            {
                a[j] = a[j-h];
                j-=h;
            }
            a[j] =r;
        }
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

