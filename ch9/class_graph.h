#ifndef CLASS_GRAPH_H_INCLUDED
#define CLASS_GRAPH_H_INCLUDED

#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;

class graph
{
    private:
        int ver;
        int *visit;
        list<int> *adj;
    public:
        graph(int);
        void edge(int, int);
        void print(int);
};

graph::graph(int v)
{
    this->ver = v;
    adj = new list<int>[v];
    visit = new int[v];
}
void graph :: edge(int v, int w)
{
    adj[v].push_back(w);
//    adj[w].push_back(v);
}
void graph :: print(int u)
{
    auto it = adj[u].begin();
    while(it!=adj[u].end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}

#endif // CLASS_GRAPH_H_INCLUDED
