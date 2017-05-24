#include"adjlist_graph.h"
#include<queue>

int main()
{
    gr *grp = create();
    queue<llist *> q;
    int cnt=0;
    cout<<"indegree of every vertex is: ";
    for(int i=0; i<grp->v; i++)
    {
        cout<<grp->adj[i]->indegree<<" ";
        if(grp->adj[i]->indegree==0)
            q.push(grp->adj[i]);
    }
    cout<<endl;
    cout<<"Topological sort ";
    while(!q.empty())
    {
        llist *temp = q.front();
        cout<<temp->vno<<" ";
        q.pop();
        int k;
        cnt++;
        for(k=0; k<grp->adj[temp->vno]->next.size(); k++)
        {
            grp->adj[temp->vno]->next[k]->indegree--;
            if(grp->adj[temp->vno]->next[k]->indegree==0)
                q.push(grp->adj[temp->vno]->next[k]);
        }
    }
    if(cnt!=grp->v)
        cout<<"does n't exist becoz Cycle exist in graph.";
    return 0;
}
