#include"adjlist_graph.h"
#include<queue>

int main()
{
    gr *grp = create();
    queue<llist*> q;
    int dist[grp->v], path[grp->v];
    q.push(grp->adj[0]);

    for(int i=0; i<grp->v; i++)
        dist[i]=-1;
    dist[0]=0;

    for(int i=0; i<grp->v; i++)
        path[i]=-1;

    while(!q.empty())
    {
        llist *temp = q.front();
        q.pop();
        for(int i=0; i<grp->adj[temp->vno]->next.size(); i++)
        {
            llist *t = grp->adj[temp->vno]->next[i];
            if(dist[t->vno]==-1)
            {
                dist[t->vno] = dist[temp->vno]+1;
                path[t->vno] = temp->vno;
                q.push(t);
            }
        }
    }
    for(int i=0; i<grp->v; i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    for(int i=0; i<grp->v; i++)
        cout<<path[i]<<" ";

    return 0;
}
