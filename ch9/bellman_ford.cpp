#include"adjlist_graph.h"
#include<algorithm>
#include<iterator>
#include<map>
#include<limits.h>
#include<queue>

/*
4 4
0 1 2
0 2 3
1 3 4
2 3 5

5 6
0 1 4
0 2 1
2 1 2
2 3 4
1 4 -4
3 4 4
*/
int main()
{
    gr *grp = create();
    int i,newd;
    llist *svrtx = grp->adj[0];
    queue<llist*> q;
    q.push(svrtx);
    int dist[grp->v], path[grp->v];

    for(int i=0; i<grp->v; i++)
        dist[i]=INT_MAX;
    dist[0]=0;

    for(int i=0; i<grp->v; i++)
        path[i]=-1;

    while(!q.empty())
    {
        svrtx = q.front();
        q.pop();
        svrtx->visited=1;
        llist *temp = grp->adj[svrtx->vno];

        for(int j=0; j < temp->next.size(); j++)
        {
            newd = dist[svrtx->vno] + temp->edge[j];
            if(dist[temp->next[j]->vno] > newd)
            {
                dist[temp->next[j]->vno] = newd;
                path[temp->next[j]->vno] = svrtx->vno;
                if(temp->next[j]->visited==0)
                {
                    q.push(temp->next[j]);
                    temp->next[j]->visited==1;
                }
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

