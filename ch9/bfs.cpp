#include "adjlist_graph.h"
#include <queue>

queue<llist*> q;

void bfs(gr *grp, int u)
{
    if(!grp->adj[u]->visited)
        cout<<grp->adj[u]->vno<<" ";
    grp->adj[u]->visited = 1;

    for(int j=0; j < grp->adj[u]->next.size(); j++)
        if(!grp->adj[u]->next[j]->visited)
            q.push(grp->adj[u]->next[j]);

    while(!q.empty())
    {
        llist *temp = q.front();
        q.pop();
        bfs(grp,temp->vno);
    }
}

int main()
{
    gr *grp = create();
    for(int i=0;i<grp->v;i++)
        if(!grp->adj[i]->visited)
            bfs(grp,grp->adj[i]->vno);
    return 0;
}
