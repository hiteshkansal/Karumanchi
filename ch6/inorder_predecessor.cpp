#include "bst.h"

node* inorder_pred(node *root, int data, node **prev)
{
    static int a=0;
    if(!root)
        return NULL;
    node *temp = inorder_pred(root->left,data,prev);
    if(temp)
        return temp;
    if(root->data == data){
        a=1;
        return *prev;
    }
    if(!a){
        *prev =root;
        return inorder_pred(root->right,data,prev);
    }
    else
        return NULL;
}
int main()
{
    node *root = NULL,*prev = NULL;
    int c =6;
    root = insrt(root,10);
    root = insrt(root,8);
    root = insrt(root,15);
    root = insrt(root,6);
    root = insrt(root,9);
    root = insrt(root,13);
    root = insrt(root,19);
    //root = insrt(root,9);
    pre(root);
    inorder_pred(root,c,&prev);
    if(prev)
        cout<<endl<<prev->data;
    else
        cout<<"\nNo Predecessor";
    return 0;
}
