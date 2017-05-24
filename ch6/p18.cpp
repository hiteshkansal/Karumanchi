#include "fullBTree.h"

int height(node *root)
{
    if(!root)
        return NULL;
    int l,r;
    l = height(root->left);
    r = height(root->right);
    return 1+ max(l,r);
}

int diameter(node *root)
{
    int lftd,rghtd,lfth,rghth;
    if(!root)
        return 0;

        lfth = height(root->left);
        rghth = height(root->right);

        lftd = diameter(root->left);
        rghtd = diameter(root->right);

        return max(lfth+rghth+1,max(lftd,rghtd));
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    cout<<"Diameter: "<<diameter(nd);
    return 0;
}

