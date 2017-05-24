#include "circuler.h"

int main()
{
    node *head,*p;
    int m,n;
    cout<<"how many node u want to create. minimum 1: ";
    cin>>n;
    head = llist(n);
    p=head;
    cout<<"Enter M: ";
    cin>>m;
    for(int i=n;i>1;i--)
    {
        for(int j=1;j<m-1;j++)
            p=p->next;

            p->next = p->next->next;
            p=p->next;
    }
    cout<<"Last player: "<<p->data;
    return 0;
}
