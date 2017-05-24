#include"adjlist_graph.h"
#include<stack>
stack<llist*>s;

void dfs(gr *grp, int u)
{
    if(!grp->adj[u]->visited)
        cout<<grp->adj[u]->vno<<" ";
    grp->adj[u]->visited = 1;

    for(int j=0; j < grp->adj[u]->next.size(); j++)
    {
        if(!grp->adj[u]->next[j]->visited)
        s.push(grp->adj[u]->next[j]);
    }

    while(!s.empty())
    {
        llist *temp = s.top();
        s.pop();
        dfs(grp,temp->vno);
    }
}
int main()
{
    gr *grp = create();

    for(int i=0;i<grp->v;i++)   //if graph is disconnected
        if(!grp->adj[i]->visited)
            dfs(grp,grp->adj[i]->vno);

    return 0;
}
