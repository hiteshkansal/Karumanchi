#include"fullBTree.h"


node *LCA(node *root, node *a, node* b)
{
    node *l,*r;
    if(!root)
        return NULL;

    if(root == a || root == b)
        return root;

    l=LCA(root->left,a,b);
    r=LCA(root->right,a,b);

    if(l&&r)
        return root;
    else
        return (l?l:r);
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*a,*b,*result;
    nd = tree(nd,n+1);
    a = nd->left->left;
    b = nd->right->right;
    result = LCA(nd,a,b);
    cout<<"LCA: "<<result->data;
    return 0;
}
