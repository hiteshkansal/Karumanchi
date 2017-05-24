#include "circ_ll.h"

int loop(struct node **p, struct node **q)
{
    while(*p && *q)
    {
        *p=(*p)->next;
        if(*p==NULL)
            return 0;
        *p=(*p)->next;
        *q=(*q)->next;
        if(*p==*q)
            return 1;
    }
    return 0;
}

int main()
{
    node *head,*p,*q;
    head = llist();
    p=q=head;
    if(loop(&p,&q))
    {
        p=head;
        while(p!=q)
        {
            p=p->next;
            q=q->next;
        }
        cout<<"Loop node address is "<<p<<" and value= "<<p->data;
    }
    else
        cout<<"no loop";
        return 0;
}
