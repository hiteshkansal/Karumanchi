#include "fullBTree.h"

node* find1(node * root,int v)
{
    node *temp=root;
    if(root!=NULL)
    {
        if(root->data == v)
            return temp;
        else
        {
            temp = find1(root->left,v);
            temp = find1(root->right,v);
        }
    }
    return temp;
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*r;
    nd = tree(nd,n+1);
    r = find1(nd,5);
    if(r!=NULL)
    cout<<"Node Address is: "<<r<<" data: "<<r->data;
    else
    cout<<"data is not present.";
    return 0;
}
