#include"adjlist_graph.h"

void print(gr *grp)
{
    for(int i=0;i<grp->v;i++)
    {
        cout<<grp->adj[i]->vno<<":   ";
        int j;
        for(j=0;j<grp->adj[i]->next.size();j++)
        {
            cout<<grp->adj[i]->next[j]->vno<<" ";
            cout<<grp->adj[i]->edge[j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    gr *grp = create();
    if(grp)
    print(grp);
    return 0;
}

