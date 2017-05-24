#include<iostream>
#include<set>
using namespace std;

typedef struct edge
{
    int s;
    int d;
}edge;
/*
6 7
0 1
0 2
1 3
2 1
3 5
0 4
4 5
*/
int main()
{
    int e,v;
    cin>>v>>e;
    edge ed[e];
    for(int i=0;i<e;i++)
        cin>>ed[i].s>>ed[i].d;

    int mark[v];
    for(int j=0;j<v;j++)
        mark[j]=0;
    set<edge*> st;
    for(int i=0;i<e;i++)
    {
        if((mark[ed[i].s]) && (mark[ed[i].d]))
            continue;
        if(!(mark[ed[i].s]))
        {
            st.insert(&ed[i]);
            mark[ed[i].s] = 1;
            mark[ed[i].d] = 1;
        }
        else if(!(mark[ed[i].d]))
        {
            st.insert(&ed[i]);
            mark[ed[i].s] = 1;
            mark[ed[i].d] = 1;
        }
    }
    auto res = st.begin();
    while(res!=st.end())
    {
       cout<<(*res)->s<<"  "<<(*res)->d<<endl;
        res++;
    }
    return 0;
}
