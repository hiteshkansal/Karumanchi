#include<iostream>
#include"fullBTree.h"

int cnt = 0;
void leaves(node *root)
{
    if(!root)
        return;
    if(!root->left && !root->right)
        cnt++;
    leaves(root->left);
    leaves(root->right);
}

int main()
{
    int l;
    node *nw = NULL;
    cout<<"levels: ";
    cin>>l;
    nw = tree(nw,l+1);
    leaves(nw);
    cout<<cnt;
    return 0;
}
