#include "fullBTree.h"

void pre(node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        pre(p->left);
        pre(p->right);
    }
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    pre(nd);
    return 0;
}

