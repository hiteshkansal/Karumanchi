#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;

class graph
{
    private:
        int ver;
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
int main()
{
    int v;
//    cout<<"Enter vertex: ";
  //  cin>>v;
    graph g(5);
    g.edge(1,2);
    g.edge(1,3);
    g.edge(2,4);
    g.edge(3,4);
    g.edge(4,5);
    g.edge(0,1);
    for(int i=0;i<5;i++)
    {
        cout<<i<<"-->";
        g.print(i);
    }
    return 0;
}
