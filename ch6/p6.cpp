#include "fullBTree.h"

int sizeoftree(node * root)
{
    if(!root)
        return 0;
    else
    {
        return 1+sizeoftree(root->left)+sizeoftree(root->right);
    }
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*r;
    nd = tree(nd,n+1);
    cout<<sizeoftree(nd);
    return 0;
}
