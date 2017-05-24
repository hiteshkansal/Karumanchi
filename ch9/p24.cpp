#include<iostream>
#include<set>
using namespace std;

typedef struct edge
{
    int s;
    int d;
} edge;
/*
4 5
0 2
0 3
2 3
3 1
1 2
*/
bool has_cycle(edge *ed, int mark[], int e)
{
    for(int i=0; i<e; i++)
    {
        if(mark[ed[i].d])
            return 1;
        else
            mark[ed[i].s] = 1;
    }
    return 0;
}

int main()
{
    int e,v;
    cin>>v>>e;
    edge ed[e];
    for(int i=0; i<e; i++)
        cin>>ed[i].s>>ed[i].d;

    int mark[v];
    for(int j=0; j<v; j++)
        mark[j]=0;
    if(has_cycle(ed,mark,e))
        cout<<"Has Cycle";
    else
        cout<<"No cycle";
    return 0;
}
