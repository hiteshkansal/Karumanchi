#include"linkedlist.h"

int printrev(struct node *s)
{
    if(s==NULL)
        return 0;
    else
    {
        printrev(s->next);
        cout<<s->data<<endl;
        return 1;
    }
}
int main()
{
    struct node *head;
    head = llist();
    cout<<"Reverse list is:"<<endl;
    printrev(head);
    return 0;
}
