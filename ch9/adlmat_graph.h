#ifndef ADLMAT_GRAPH_H_INCLUDED
#define ADLMAT_GRAPH_H_INCLUDED
#include<iostream>
#include<stdlib.h>

int vertices;
using namespace std;

typedef struct graph
{
    int v;
    int e;
    int *visit;
    int **adj;
}graph;

graph* create()
{
    int k,l;
    graph *gr = new graph;
    cout<<"how many vertces and edges: ";
    cin>>gr->v>>gr->e;
    vertices = gr->v;
    gr->adj = new int*[gr->v];
    for(int i=0;i<gr->v;i++)
        gr->adj[i]=new int[gr->v];

    for(int i=0; i < gr->v; i++)
        for(int j=0; j < gr->v; j++)
            gr->adj[i][j]=0;
    gr->visit = new int[gr->v];
     for(int i=0;i<gr->v;i++)
        {
            gr->visit[i] =0;
        }
    for(int i=0;i < gr->e;i++)
    {
        cout<<"Reading edge(0 to "<<(gr->v)-1<<"): ";
        cin>>k>>l;
        if(k < gr->v && l < gr->v)
        {
            gr->adj[k][l]= 1;
//            gr->adj[l][k]= 1;
        }
        else
        {
            i--;
            cout<<"wrong vertices."<<endl;
        }
    }
    return gr;
}
#endif // ADLMAT_GRAPH_H_INCLUDED
