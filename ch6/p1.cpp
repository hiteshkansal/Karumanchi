#include "fullBTree.h"
#include<limits.h>

int maxm(node * root)
{
    int mx = INT_MIN,lft,rght,rt;
    if(root!=NULL)
    {
        rt = root->data;
        lft = maxm(root->left);
        rght = maxm(root->right);
        if(lft>rght)
        mx = lft;
        else
        mx = rght;
        if(rt>mx)
        mx=rt;
    }
    return mx;
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    cout<<"Max: "<<maxm(nd);
    return 0;
}
