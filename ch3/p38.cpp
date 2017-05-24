#include "linkedlist.h"
/*
node* getkplusone(int k, node *head)
{
    node *kth=head;
    int i=0;
    if(!head)
        return head;
    while(kth&&(i<k))
    {
        kth=kth->next;
        i++;
    }
    return kth;
}
int hasnode(node *head,int k)
{
    int i;
    for(i=0; head&&(i<k);i++,head = head->next);
        if(i==k)
        return 1;
    return 0;
}

int main()
{
    node *head,*cur,*temp,*nxt,*newhead,*temp2;
    int i=0,k;
    head = llist();
    cur=head;
    cout<<"Enter K: ";
    cin>>k;
    if(k==0||k==1){
        printlist(head);
        return 0;
    }
    if(hasnode(cur, k-1))
        newhead = getkplusone(k-1,cur);
    else
        newhead = head;

    while(cur && hasnode(cur,k))
    {
        temp = getkplusone(k,cur);
        temp2=cur;
        i=0;
        while(i<k)
        {
            nxt=cur->next;
            cur->next = temp;
            temp = cur;
            cur = nxt;
            i++;
        }
        if(hasnode(cur,k))
        temp2->next = getkplusone(k-1,cur);
    }
    printlist(newhead);
    return 0;
}
*/
node* revers(struct node* head, int k)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    struct node *pr, *cr,*nxt;
    pr= NULL;
    cr = head;
    int cnt = 0;
    while(cr &&cnt<k)
    {
        nxt = cr->next;
        cr->next = pr;
        pr = cr;
        cr = nxt;
        cnt++;
    }
    if(nxt)
        head->next = revers(nxt,k);
    return pr;
}

int main()
{
    struct node *head,*p;
    head = llist();
    int k;
    cout<<"\nEnter k: ";
    cin>>k;
    p = revers(head,k);
    printlist(p);
    return 0;
}
