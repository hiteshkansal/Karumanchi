#include "circ_ll.h"
//#include "linkedlist.h"
extern int m;

int main()
{
    struct node *head,*p;
    int n,i=0,flag=1;
    head = llist();
    p=head;
    struct node *hash1[m];

    while(flag)
    {
        hash1[i]= p->next;
        p=p->next;
        for(n=0;n<=i;n++)
        {
            if(p->next==hash1[n])
            {
                cout<<"There is loop at address "<<p->next<<" and data value is "<<p->next->data<<endl;;
                flag=0;
            }
        }
        i++;
        if(p->next==NULL)
        {
            cout<<"There is no loop.";
            free(hash1);
            flag = 0;
        }
    }
    return 0;
}
