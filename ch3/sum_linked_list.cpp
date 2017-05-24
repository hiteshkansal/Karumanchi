#include"linkedlist.h"

int c=0;
node* create_node(int value)
{
    node * nw = (struct node *)malloc(sizeof(node));
    nw->data = value;
    nw->next = NULL;
    return nw;
}

node* revrse(node* head)
{
    if(!head)
        return NULL;
    if(head->next == NULL)
        return head;
    node *sec = head->next;
    head->next = NULL;
    node *sec_elm = revrse(sec);
    sec->next = head;
    return sec_elm;
}

node *add(int a, int b, node *temp)
{
    int val = c+a+b;
    if(val>=10)
    {
        c = 1;
        val = val%10;
    }
    else
        c=0;
    node* nw = create_node(val);
    temp->next = nw;
    temp = nw;
    return temp;
}

node* sum(node* p, node* q)
{
    if(!p && !q)
        return NULL;
    if(!p)
        return q;
    if(!q)
        return p;
    node *a, *b;
    a = revrse(p);
    b = revrse(q);
    int val;

    node* temp = create_node(100);
    node* head = temp;
    while(a!=NULL && b!= NULL)          //If both are of same size.
    {
        temp = add(a->data,b->data,temp);
        a = a->next;
        b = b->next;
    }
    if(a==NULL && b!=NULL)              // if a is smaller
    {
        while(b!=NULL)
        {
           temp = add(0,b->data,temp);
           b = b->next;
        }
    }
    if(a!=NULL && b==NULL)          // if b is smaller
    {
        while(a!=NULL)
        {
           temp = add(a->data,0,temp);
           a = a->next;
        }
    }
    if(c)                           // if carry at MSB
    {
        temp->next = create_node(c);
    }
    temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
    return revrse(head);
}

int main()
{
    int n;
    struct node *p,*head, *res;
    head = llist();
    p = llist();
    res = sum(head, p);
    printlist(res);
    return 0;
}
