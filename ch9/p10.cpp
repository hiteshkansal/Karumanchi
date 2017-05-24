/*
#include"adjlist_graph.h"
#include<stack>
stack<llist*>s;

int dfs(gr *grp, int u, int v)
{
    if(u==v)
        return 1;
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
        if(dfs(grp,temp->vno,v))
            return 1;
    }
    return 0;
}

int main()
{
    gr *grp = create();
    int s,d;
    cout<<"Enter source and destination: ";
    cin>>s>>d;
    if(dfs(grp,s,d))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
*/
/*
4 3
0 1
0 2
1 2
0 3
*/
#include"adlmat_graph.h"


int haspath(graph *grp, int s, int d)
{
    int t;
    grp->visit[s]=1;
    if(s==d)
    {
        return 1;
    }
    for(t=0;t<grp->v;t++)
    {
        if((grp->adj[s][t]) && !(grp->visit[t]))
        {
               if(haspath(grp,t,d))
               {
                    return 1;
               }
        }
    }
    return 0;
}

int main()
{
    int s,d;
    graph *grp = create();
    cout<<"Enter source and dest: ";
    cin>>s>>d;
    if(haspath(grp,s,d))
        cout<<"Yes";
    else
        cout<<"NO";
    return 0;
}
