#include "linkedlist.h"

int count;

void count_node(struct node *d)
{
    count=0;
    while(d)
    {
        //cout<<d->data<<endl;
        d=d->next;
        count++;
    }
}

int main()
{
    int n;
    struct node *p,*head;
    head = llist();
    cout<<"which node from the last u wanna find: ";
    cin>>n;
    p=head;
    count_node(p);
    if(count<n)
        cout<<"less no of nodes in the linked list";
    else
    {
       while(p!=NULL)
        {
            p=p->next;
            count_node(p);

            if(count==n)
                cout<<"Value of "<<n<<"th last element is: "<<p->data;
        }
    }
    return 0;
}
