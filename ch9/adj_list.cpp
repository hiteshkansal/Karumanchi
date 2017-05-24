#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct linkedlist
{
    int vno;
    struct linkedlist *next;
} llist;

typedef struct graph
{
    int v;
    int e;
    llist *adj;
} gr;

llist* createnode(int v)
{
    llist *nw = new llist;
    if(!nw)
        return NULL;

    nw->vno=v;
    nw->next=NULL;
    return nw;
}
gr* create()
{
    gr *g =new gr;
    int a,b;
    cout<<"Enter total vertices and edges: ";
    cin>>a>>b;
    if(a==0)
        return NULL;
    g->v = a;
    g->e = b;
    g->adj = (llist*)malloc(sizeof(llist)*(g->v));
    if(!g)
        return NULL;

    for(int i=0; i < g->v; i++)
    {
        ((g->adj)+i)->vno = i;
        ((g->adj)+i)->next = NULL;
    }
    llist *temp = NULL,*nw = NULL;
    for(int i=0; i < g->e; i++)
    {
        cout<<"Enter vertices having edges incident(vertex no. 0 to "<<(g->v)-1<<" : ";
        cin>>a>>b;
        if(a>=(g->v) || b>=(g->v))
        {
            cout<<"Enter correct vertex no.\n";
            i--;
        }
        else
        {
            nw= createnode(b);
            if(!nw)
            {
                i--;
                continue;
            }
            temp = ((g->adj)+a);
            while(temp->next)
                temp = temp->next;
            temp->next = nw;
            nw= createnode(a);
            if(!nw)
            {
                i--;
                continue;
            }
            temp = ((g->adj)+b);
            while(temp->next)
                temp = temp->next;
            temp->next = nw;
        }
    }
    return g;
}

void print(gr *grp)
{
    llist *temp;
    for(int i=0; i<grp->v; i++)
    {
        temp = ((grp->adj)+i);
        cout<<"list of "<<i<<" vertices: ";
        while(temp->next)
        {
            temp = temp->next;
            cout<<temp->vno<<" ";
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
