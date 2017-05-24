#include "linkedlist.h"

extern int m;
int count1=0;

typedef struct hash1
{
    int key;
    struct node* addr;
}hash1;

int main()
{
    int n,pos,i=0;
    struct node *p,*head;
    head=llist();
    hash1 h[m];
    cout<<"which node from the last u wanna find: ";
    cin>>n;
    p=head;
    while(p)
    {
        count1++;
        h[i].key = count1;
        h[i].addr = p;
        p=p->next;
        i++;
    }

    if(count1<n)
        cout<<"less no of nodes in the linked list";
    else
    {
        pos= count1-n;
        cout<<n<<" node store at address: "<<h[pos].addr<<endl;
        cout<<"And its data part is: "<<(h[pos].addr)->data<<endl;
    }
    return 0;
}
