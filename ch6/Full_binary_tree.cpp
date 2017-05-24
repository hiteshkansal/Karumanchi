#include "fullBTree.h"

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    cout<<nd->left->data<<" "<<nd->right->data;
    return 0;
}
