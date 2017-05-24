#include "fullBTree.h"

void post(node *p)
{
    if(p)
    {
        post(p->left);
        post(p->right);
        cout<<p->data<<" ";
    }
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    post(nd);
    return 0;
}


