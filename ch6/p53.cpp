#include "bst.h"
node *head = NULL;
/*
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
*/
void BSTtoDLL(node *root)
{
    static node *prev=NULL;
    static int a=0;
    if(root)
    {
        BSTtoDLL(root->left);
        if(prev)
            prev->right = root;
        root->left = prev;
        prev  =root;
        if(!a)
        {
            a=1;
            head =root;
        }
        BSTtoDLL(root->right);
    }
}

int main()
{
    node *root = NULL,*n;
    root = insrt(root,12);
    root = insrt(root,1);
    root = insrt(root,2);
    root = insrt(root,20);
    root = insrt(root,15);
    root = insrt(root,24);
    root = insrt(root,18);
    root = insrt(root,9);
    inorder(root);
    cout<<endl;
    BSTtoDLL(root);

  //  head = BSTtoDLL(root,&n);
    while(head->right!=NULL)
    {
        cout<<head->data<<" ";
        head = head->right;
    }
    cout<<head->data;
    cout<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->left;
    }

    return 0;
}
