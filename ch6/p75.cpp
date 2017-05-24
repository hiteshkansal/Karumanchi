#include"bst.h"
#include<stdlib.h>

int isavl(node *root)
{
    int l,r;
    if(!root)
        return NULL;
    l = isavl(root->left);
    if(l==-1)
        return l;
    r = isavl(root->right);
    if(r==-1)
        return r;
    if(abs(l-r)>1)
        return -1;
    return max(l,r)+1;
}

int main()
{
    node *root = NULL,*temp;
    root = insrt(root,4);
    root = insrt(root,12);
    root = insrt(root,1);
    root = insrt(root,67);
    root = insrt(root,9);
    root = insrt(root,44);
    root = insrt(root,35);
    if(isavl(root)<0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
