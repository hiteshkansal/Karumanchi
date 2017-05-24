#include"linkedlist.h"
/*
node * reverse2(node *head)
{
    if(!head)
        return NULL;
    if(!(head->next))
        return head;
    node *start, *temp,*temp2;
    start = temp2 = head;
    head = head->next;
    while(start && start->next)
    {
        temp2->next = start->next;
        temp = start->next;
        start->next = temp->next;
        temp->next = start;
        temp2 = start;
        if(start)
            start = start->next;
    }
    return head;
}
*/
node* reverse2(struct node* head)
{
    if(head==NULL)
        return NULL;
    if(head->next==NULL)
        return head;
    struct node *pr, *cr,*nxt;
    pr= NULL;
    cr = head;
    int cnt=0;
    while(cr && cnt<2)
    {
        nxt = cr->next;
        cr->next = pr;
        pr = cr;
        cr = nxt;
        cnt++;
    }
    if(nxt)
        head->next = reverse2(nxt);
    return pr;
}

int main()
{
    struct node *head,*p;
    head = llist();
    p = reverse2(head);
    printlist(p);
    return 0;
}
