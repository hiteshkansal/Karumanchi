#include "adlmat_graph.h"

int main()
{
    graph *gr = new graph;
    gr = create();
    for(int i=0; i < gr->v; i++)
    {
        for(int j=0; j < gr->v; j++)
            cout<<gr->adj[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
