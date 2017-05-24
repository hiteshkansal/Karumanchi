#include"bst.h"

node* kthsmallest(node* root, int k, int *cnt)
{
    if(!root)
        return NULL;

    node* lft = kthsmallest(root->left,k,cnt);
    if(lft)
    return lft;
    if(++*cnt == k)
    return root;

    return kthsmallest(root->right,k,cnt);
}
int main()
{
    node *root = NULL,*n;
    int c = 0,*cnt = &c;
    root = insrt(root,12);
    root = insrt(root,1);
    root = insrt(root,2);
    root = insrt(root,20);
    root = insrt(root,15);
    root = insrt(root,24);
    root = insrt(root,18);
    root = insrt(root,9);

    inorder(root);

    n = kthsmallest(root,5,cnt);
    cout<<endl<<(n->data);
    return 0;
}
