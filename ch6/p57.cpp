#include "linkedlist.h"

typedef struct bsttree
{
    struct bsttree *left;
    int data;
    struct bsttree *right;
}bst;

bst* makenode(int data)
{
    bst *root = new bst;
    root->data = data;
    root->left = root->right = NULL;
    return root;
}

void inorder(bst *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

void preorder(bst *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        inorder(p->left);
        inorder(p->right);
    }
}

node *findmiddle(node *lst)
{
    node *slow = lst;
    while(lst->next)
    {
        lst = lst->next;
        slow = slow->next;
        if(!lst->next)
            break;
        lst = lst->next;
    }
    return slow;
}

bst* LLtoBST(node *head)
{
    node *temp,*p,*q;
    if(!head)
        return NULL;
    if(!(head->next))
    {
        bst *root = makenode(head->data);
        return root;
    }
    temp = findmiddle(head);
  //  cout<<"temp: "<<temp->data<<endl;
    p = head;
    bst *root = makenode(temp->data);
    while(p->next!=temp)
        p = p->next;
  //  cout<<"p: "<<p->data<<endl;
    p->next = NULL;
    q = temp->next;
    temp->next = NULL;
    root->left = LLtoBST(head);
    root->right = LLtoBST(q);
    return root;
}

int main()
{
    node *p,*head;
    bst *n;
    head=llist();
    printlist(head);
    cout<<endl<<"Inorder: ";
    n = LLtoBST(head);
    inorder(n);
    cout<<endl<<"Preorder: ";
    preorder(n);
    return 0;
}
