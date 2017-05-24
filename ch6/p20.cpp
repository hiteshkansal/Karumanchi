#include "fullBTree.h"

void print(int path[], int len)
{
    for(int i=0;i<len;i++)
    cout<<path[i]<<" ";
}

void path1(node* root, int path[], int len)
{
    if(!root)
        return;
    path[len++] = root->data;
    if(root->left==NULL && root->right ==NULL)
    {
        print(path,len);
        cout<<endl;
    }
    else
    {
        path1(root->left,path,len);
        path1(root->right,path,len);
    }
}

int main()
{
    int n,len=0;
    cout<<"How many level u want: ";
    cin>>n;
    int path[n];
    node *nd = NULL;
    nd = tree(nd,n+1);
    path1(nd,path,len);
    return 0;
}
