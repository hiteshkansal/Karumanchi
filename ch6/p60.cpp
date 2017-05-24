#include"bst.h"

node* floor(node *root, node **prev, int dat)
{
    node *temp;
    if(!root)
        return NULL;
    if(temp = floor(root->left, prev, dat))
        return temp;
    if(root->data == dat)
        return root;
    if(root->data > dat)
        return *prev;
    *prev = root;
    return floor(root->right, prev, dat);
}

node* ceil(node *root, node **prev, int dat)
{
    node *temp;
    if(!root)
        return NULL;
    if(temp = ceil(root->right, prev, dat))
        return temp;
    if(root->data == dat)
        return root;
    if(root->data < dat)
        return *prev;
    *prev = root;
    return ceil(root->left, prev, dat);
}

int main()
{
    node *root = NULL, *prev = NULL,*flr;
    root = insrt(root,6);
    root = insrt(root,1);
    root = insrt(root,10);
    root = insrt(root,8);
    root = insrt(root,15);
    root = insrt(root,3);
    root = insrt(root,19);
    inorder(root);
    cout<<endl;
    /*
    flr = floor(root,&prev,0);
    if(flr)
        cout<<flr->data;
    else if(prev == NULL)
        cout<<"Floor doesnt exist";
    else
    cout<<prev->data;
    */
    flr = ceil(root,&prev,14);
    if(flr)
        cout<<flr->data;
    else if(prev == NULL)
        cout<<"Ceiling doesnt exist";
    else
    cout<<prev->data;
    return 0;
}
