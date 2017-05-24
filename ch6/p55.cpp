#include "bst.h"

node* BSTtoDLL(node *root, node **L)
{
    node *left, *right, *ltail, *rtail;
    if(!root)
    {
        *L = NULL;
        return NULL;
    }
    left = BSTtoDLL(root->left, &ltail);
    right = BSTtoDLL(root->right, &rtail);
    root->left = ltail;
    root->right = right;
    if(!right)
        *L = root;
    else
    {
        right->left = root;
        *L = rtail;
    }
    if(!left)
        return root;
    else
    {
        ltail->right = root;
        return left;
    }
}

node *findmiddle(node *lst)
{
    node *slow = lst;
    while(lst->right)
    {
        lst = lst->right;
        if(!lst->right)
            break;
        lst = lst->right;
        slow = slow->right;
    }
    return slow;
}
node* DLLtoBST(node *head)
{
    node *p,*q,*temp;
    if(!head || !(head->right))
        return head;
    temp = findmiddle(head);
    if(head==temp)
    {
        head->right->left = NULL;
        return temp;
    }
    p = temp->left;
    p->right = NULL;
    q = temp->right;
    q->left = NULL;
    temp->right = NULL;
    temp->left = DLLtoBST(head);
    temp->right = DLLtoBST(q);
    return temp;
}

int main()
{
    node *root = NULL,*n,*lst;
  /*  root = insrt(root,12);
    root = insrt(root,7);
    root = insrt(root,2);
    root = insrt(root,20);
    root = insrt(root,15);
    root = insrt(root,24);
    root = insrt(root,8);
    root = insrt(root,9);
    root = insrt(root,19);
   */
    root = insrt(root,3);
    root = insrt(root,1);
    root = insrt(root,2);
    root = insrt(root,0);
    root = insrt(root,5);
    root = insrt(root,4);
    root = insrt(root,6);

    inorder(root);
    cout<<endl;
    lst = BSTtoDLL(root,&n);
    cout<<endl;
    n = DLLtoBST(lst);
    inorder(n);
    return 0;
}
