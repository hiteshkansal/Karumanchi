#include"adjlist_graph.h"
#include<algorithm>
#include<map>
#include<limits.h>

/*
4 4
0 1 2
0 2 3
1 3 4
2 3 5

4 4
0 1 3
0 3 -5
1 2 -5
3 2 8

5 6
0 1 4
0 2 1
2 1 2
2 3 4
1 4 4
3 4 4
*/

int main()
{
    gr *grp = create();
    int i,newd;
    int dist[grp->v], path[grp->v];
    llist *svrtx = NULL;
    multimap<int,llist*> pq;

    pq.insert( {-1,grp->adj[0]});
    grp->adj[0]->visited = 1;

    for(int i=0; i<grp->v; i++)
        dist[i]=INT_MAX;
    dist[0]=0;

    for(int i=0; i<grp->v; i++)
        path[i]=-1;
    while(!pq.empty())
    {
        svrtx = pq.begin()->second;
        pq.erase(pq.begin());
        llist *temp = grp->adj[svrtx->vno];
        for(int j=0; j < temp->next.size(); j++)
        {
            newd = dist[svrtx->vno] + temp->edge[j];
            if(!(temp->next[j]->visited)  && dist[temp->next[j]->vno] > newd)
            {
                dist[temp->next[j]->vno] = newd;
                pq.insert( {temp->edge[j],temp->next[j]});
                path[temp->next[j]->vno] = svrtx->vno;
                temp->next[j]->visited = 1;
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
