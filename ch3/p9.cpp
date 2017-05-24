//#include "circ_ll.h"
#include "linkedlist.h"


int loop(struct node *p, struct node *q)
{
    while(p && q)
    {
        p=p->next;
        if(p==NULL)
            return 0;
        p=p->next;
        q=q->next;
        if(p==q)
            return 1;
    }
    return 0;
}

int main()
{
    struct node *head,*p,*q;
    head = llist();
    p=q=head;
    if(loop(p,q))
        cout<<"loop";
    else
        cout<<"no loop";

    /* while(p!=q ||(p!=NULL && q!=NULL))
     {
         p=p->next->next;
         q=q->next;
         if(p==q)
         {
             cout<<"There is loop"<<endl;    //this is wrong becoz p->next->next can cause (null->next)
             break;                          // suppose if p->next=null then p->next->next becomes NULL->next
         }                                   //which is wrong.
         if(p==NULL || q==NULL)
         {
             cout<<"No loop"<<endl;
             break;
         }
     }
     */
     return 0;
}
