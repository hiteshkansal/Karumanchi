#ifndef ADJLIST_GRAPH_H_INCLUDED
#define ADJLIST_GRAPH_H_INCLUDED

#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

typedef struct linkedlist
{
    int vno;
    int visited;
    int indegree;
    vector<int> edge;
    vector<struct linkedlist *> next;
} llist;

typedef struct graph
{
    int v;
    int e;
    vector<llist *> adj;
} gr;

gr* create()
{
    gr *g =new gr;
    if(!g)
        return NULL;
    int a,b,c;
    cout<<"Enter total vertices and edges: ";
    cin>>g->v>>g->e;
    if(g->v==0)
        return NULL;

    for(int i=0; i < g->v; i++)
    {
        llist *v = new llist;
        v->vno=i;
        v->visited=0;
        v->indegree=0;
        g->adj.push_back(v);
    }
    for(int i=0; i < g->e; i++)
    {
       // cout<<"Enter vertices having edges incident(vertex no. 0 to "<<(g->v)-1<<"): ";
        cin>>a>>b;
       // cout<<"Enter weight ";
        cin>>c;
        if(a>=(g->v) || b>=(g->v))
        {
            cout<<"Enter correct vertex no.\n";
            i--;
        }
        else
        {
            g->adj[a]->next.push_back(g->adj[b]);
          //  g->adj[b]->next.push_back(g->adj[a]);        //remove this to make it directed.
        }
        g->adj[b]->indegree++;
        g->adj[a]->edge.push_back(c);
    }
    return g;
}

#endif // ADJLIST_GRAPH_H_INCLUDED
