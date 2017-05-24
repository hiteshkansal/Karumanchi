#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<iterator>
using namespace std;

typedef struct Edge
{
    int src, dest, weight;
} Edge;

typedef struct graph
{
    int v,e;
    Edge *edge;
} graph;

typedef struct subset
{
    int rnk, prnt;
}subset;

graph* create(graph *grp, int v, int e)
{
    grp = new graph;
    if(!grp)
        return NULL;
    grp->v = v;
    grp->e = e;
    grp->edge = (Edge*)malloc(sizeof(Edge)*grp->e);
    if(!(grp->edge))
        return NULL;
    return grp;
}

bool comp(Edge *a, Edge *b)
{
    return a->weight < b->weight;
}

int fnd(subset *s, int i)
{
    if(s[i].prnt !=i)
        s[i].prnt = fnd(s,s[i].prnt);

    return s[i].prnt;
}

int unin(subset *s, int x, int y)
{
    int xpr = fnd(s,x);
    int ypr = fnd(s,y);

    if (s[xpr].rnk < s[ypr].rnk)
        s[xpr].prnt = ypr;
    else if (s[xpr].rnk > s[ypr].rnk)
        s[ypr].prnt = xpr;
    else
    {
        s[ypr].prnt = xpr;
        s[xpr].rnk++;
    }
}

void kruskal(graph *grp)
{
    Edge *temp = grp->edge;
    vector<Edge*> ed;

    int cnt=0;
    for(int i=0; i<grp->e; i++)
    {
        ed.push_back(temp);
        temp++;
    }
    sort(ed.begin(), ed.end(),comp);
    auto it =  ed.begin();
    subset *s = (subset*)malloc(grp->v * sizeof(subset));

    for(int i=0; i<grp->v; i++)
    {
        s[i].prnt = i;
        s[i].rnk =0;
    }
    Edge *rslt[(grp->v)-1];

    while(cnt<grp->v-1)
    {
        it = ed.begin();
        int x = fnd(s,(*it)->src);
        int y = fnd(s,(*it)->dest);
        if (x != y)
        {
             rslt[cnt] = *it;
             unin(s,x,y);
        }
        ed.erase(it);
        cnt++;
    }
    for(int i=0; i<cnt; i++)
    {
        cout<<rslt[i]->src<<"-->"<<rslt[i]->dest<<"  "<<rslt[i]->weight<<" ";
        cout<<endl;
    }
}

int main()
{
    int v=5,e=7;
    graph *grp= NULL;
    grp = create(grp,v,e);

    grp->edge[0].src = 0;
    grp->edge[0].dest = 3;
    grp->edge[0].weight = 5;

    grp->edge[1].src = 0;
    grp->edge[1].dest = 2;
    grp->edge[1].weight = 7;

    grp->edge[2].src = 1;
    grp->edge[2].dest = 2;
    grp->edge[2].weight = 8;

    grp->edge[3].src = 2;
    grp->edge[3].dest = 3;
    grp->edge[3].weight = 9;

    grp->edge[4].src = 1;
    grp->edge[4].dest = 4;
    grp->edge[4].weight = 5;

    grp->edge[5].src = 2;
    grp->edge[5].dest = 4;
    grp->edge[5].weight = 7;

    grp->edge[6].src = 3;
    grp->edge[6].dest = 4;
    grp->edge[6].weight = 15;

    kruskal(grp);
    return 0;
}
