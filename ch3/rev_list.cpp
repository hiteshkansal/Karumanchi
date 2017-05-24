#include"linkedlist.h"

/*
int main()
{
    struct node *head,*p,*q,*r;
    head = llist();
    p=head;
    q=p->next;
    r=q->next;
    while(r!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
    q->next=p;
    head->next=r;
    head=q;
    p=head;
    cout<<"Reverse list is:"<<endl;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    return 0;
}
*/
node* reverse_list(struct node* p)
{
    if(p==NULL)
        return NULL;
    if(p->next==NULL)
        return p;
    struct node* sec = p->next;
    p->next = NULL;
    struct node *revlist = reverse_list(sec);
    sec->next = p;
    return revlist;
}

node* revers(struct node* head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    struct node *pr, *cr,*nxt;
    pr= NULL;
    cr = head;
    while(cr)
    {
        nxt = cr->next;
        cr->next = pr;
        pr = cr;
        cr = nxt;
    }
    return pr;
}
int main()
{
    struct node *head,*p;
    head = llist();
    //p = reverse_list(head);
    p = revers(head);
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
    return 0;
}
