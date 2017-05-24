#include<iostream>
#include<map>

using namespace std;

/*
5
1 4
5 7
6 8
2 9
12 15
*/
int main()
{
    multimap<int,int> m, res;
    cout<<"Enter no of intervals: ";
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        m.insert( {b,a});
    }
    auto it = m.begin();
    res.insert({it->second,it->first});
    m.erase(it);
    it = m.begin();
    auto r=res.begin();
    while(it!=m.end())
    {
        if(r->second < it->second)
        {
            res.insert( {it->second,it->first});
            m.erase(it);
            it=m.begin();
            r++;
        }
        else
            it++;
    }
    r=res.begin();
    while(r!=res.end())
    {
        cout<<r->first<<" "<<r->second<<endl;
        r++;
    }
    return 0;
}
