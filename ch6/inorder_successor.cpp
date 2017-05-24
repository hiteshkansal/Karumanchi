#include "bst.h"
/*
node* inorder_succ(node *root, int data, node **prev)
{
    static int a=0;
    if(!root)
        return NULL;
    node *temp = inorder_succ(root->right,data,prev);
    if(temp)
        return temp;
    if(root->data == data)
    {
        a=1;
        return *prev;
    }
    if(!a)
    {
        *prev =root;
        return inorder_succ(root->left,data,prev);
    }
    else
        return NULL;
}
*/

node* minv(node *root)
{
    while(root!=NULL)
    {
        if(root->left)
            root=root->left;
    }
    return root;
}

node* inorder_succ(node *root, node *n)
{
    if(n->right!=NULL)
        return minv(root->right);
    node *suc = NULL;

    while(root)
    {
        if(n->data < root->data)
        {
            suc = root;
            root = root->left;
        }
        else if(n->data > root->data)
            root = root->right;
        else
            break;
    }
    return suc;
}
int main()
{
    node *root = NULL,*prev = NULL;
    int c =19;
    root = insrt(root,10);
    root = insrt(root,8);
    root = insrt(root,15);
    root = insrt(root,6);
    root = insrt(root,9);
    root = insrt(root,13);
    root = insrt(root,19);
//    root = insrt(root,9);
    pre(root);
    cout<<endl;
    inorder(root);
  //  inorder_succ(root,c,&prev);
    node *n = root->left->right;
    prev = inorder_succ(root,n);
    if(prev)
        cout<<endl<<prev->data;
    else
        cout<<"\nNo Successor";

    return 0;
}
