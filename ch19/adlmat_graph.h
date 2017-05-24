#ifndef ADLMAT_GRAPH_H_INCLUDED
#define ADLMAT_GRAPH_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<limits.h>
int ver;
using namespace std;

typedef struct graph
{
    int v;
    int e;
    int **adj;
}graph;

graph* create()
{
    int k,l,weight;
    graph *gr = new graph;
    cout<<"how many vertces and edges: ";
    cin>>gr->v>>gr->e;
    ver = gr->v;
    gr->adj = new int*[gr->v];
    for(int i=0;i<gr->v;i++)
        gr->adj[i]=new int[gr->v];

    for(int i=0; i < gr->v; i++)
        for(int j=0; j < gr->v; j++)
            gr->adj[i][j] = 1000;

    for(int i=0;i < gr->e;i++)
    {
//        cout<<"Reading edge(0 to "<<(gr->v)-1<<"): ";
        cin>>k>>l>>weight;
        if(k < gr->v && l < gr->v)
        {
            gr->adj[k][l]= weight;
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
