#include "fullBTree.h"

node* srch(node *root, int d)
{
    node *nd = NULL;
    if(!root)
        return NULL;
    if(root->data==d)
        return root;
    else
    {
        if(root->left)
        {
            nd = srch(root->left,d);
            if(nd)
                return nd;
        }
        if(root->right)
            return srch(root->right,d);
    }
}

node* pre_succ(node *root, node *n, node **temp)
{
    static int i=0;
    if(!root)
        return NULL;

    if(root == n)
    {
        i=1;
        return (*temp)->right;
    }
    if(!i)
    {
        if(root->left)
        {
            if(root->right)
                *temp = root;
            pre_succ(root->left,n,temp);
        }
        if(root->right)
            return pre_succ(root->right,n,temp);
    }
    else
        return NULL;
}

int main()
{
    int l,d;
    cout<<"How many level u want: ";
    cin>>l;
    node *nd,*n,*temp;
    nd = tree(nd,l+1);
    cout<<"enter node: ";
    cin>>d;
    n = srch(nd,d);
    cout<<n->data;
    if(n!=NULL)
    {
        if(n->left)
            cout<<n->left->data;
        else if(n->right)
            cout<<n->right->data;
        else
        {
            cout<<"hello123";
            nd = pre_succ(nd,n,&temp);
            if(nd)
                cout<<nd->data;
            else
                cout<<"no successor";
        }
    }
    else
        cout<<"data not present.";
    return 0;
}

