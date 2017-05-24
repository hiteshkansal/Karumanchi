#include "linkedlist.h"

extern int m;

int main()
{
    struct node *head,*p,*q;
    int n,i=0;
    head = llist();
    p=q=head;
    cout<<"which node from the last u wanna find: ";
    cin>>n;
    while(p!=NULL)
    {
        if(i<n)
        {
            p=p->next;
            i++;
        }
        else
        {
            p=p->next;
            q=q->next;
        }

    }
     cout<<n<<" node store at address: "<<q<<endl;
        cout<<"And its data part is: "<<q->data<<endl;
        return 0;
}
