#include <iostream>
#include <stdlib.h>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
int isempty(struct node *top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

void push(struct node ** top,int value)
{
    struct node * nw = (struct node *)malloc(sizeof(struct node));
    nw->data =value;
    nw->next =*top;
    *top = nw;
    cout<<value<<" is pushed."<<endl;

}
void display(struct node * p)
{
    if(p==NULL)
        cout<<"stack is empty. Add elements "<<endl;
    else
    {
        cout<<"current stack content is: "<<endl;
        while(p!=NULL)
        {
            cout<<p->data<<endl;
            p=p->next;
        }
    }
}

void pop(struct node **top)
{
    struct node *temp= *top;
    if(isempty(temp))
        cout<<"Underflow. cannot delete element. First add element\n";
    else
    {
        int temp1 = (*top)->data;
        *top = (*top)->next;
        cout<<temp1<<" is popped."<<endl;
        free(temp);
    }
}
void deletestack(struct node ** top)
{
    struct node *p =*top;
    while(p!=NULL)
    {
        p=p->next;
        free(top);
        *top=p;
    }
}

int main()
{
    struct node *top = NULL;
    pop(&top);
    push(&top,2);
    push(&top,3);
    push(&top,4);
    pop(&top);
    //push(&top,13);  push(&top,23); pop(&top); push(&top,53);  push(&top,83);
    push(&top,5);
    display(top);
    deletestack(&top);
    display(top);
    return 0;
}
