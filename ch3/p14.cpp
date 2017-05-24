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
    struct node *head,*p,*q;
    int counter=0;
    head = llist();
    p=q=head;
    if(loop(&p,&q))
    {
        p=head;
        while(p!=q)
        {
            p=p->next;
            counter++;
        }
        cout<<"Loop length is: "<<counter<<endl;
    }
    else
        cout<<"no loop";
        return 0;
}
