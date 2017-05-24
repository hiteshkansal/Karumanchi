#include "fullBTree.h"

int ancester(node *root, node *v)
{
    if(!root)
        return 0;
    cout<<"Root: "<<root->data<<endl;
    if(root->left == v ||root->right == v || ancester(root->left,v) || ancester(root->right,v))
    {
        cout<<root->data<<endl;
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*v;
    nd = tree(nd,n+1);
    v=nd->left->left;
    ancester(nd,v);
    return 0;
}
