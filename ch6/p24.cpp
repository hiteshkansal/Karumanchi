#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
} node;

node * create(int a)
{
    node * nw=(node*)malloc(sizeof(node));
    if(!nw)
    {
        cout<<"No Memory"<<endl;
        return NULL;
    }
    else
    {
        nw->data = a;
        nw->left = NULL;
        nw->right = NULL;
        return nw;
    }
}

node * mirror(node *root)
{
    node *temp;
    if(!root)
        return NULL;
    else
    {
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right= temp;
    }
    return root;
}
int main()
{
    node *root,*nw;
    nw= create(1);
    root=nw;
    nw->left = create(2);
    nw->right = create(3);
    nw=nw->left;
    nw->left = create(4);
    nw->right = create(5);
    mirror(root);
    cout<<root->right->left->data;
    return 0;
}
