#ifndef FULLBTREE_H_INCLUDED
#define FULLBTREE_H_INCLUDED
#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
} node;

node* create()
{
    int a;
   // cout<<"Enter data: ";
    cin>>a;
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

node * tree(node* nw,int n)
{
    if(n==0)
    return nw;
    else{
    nw= create();
    nw->left = tree(nw->left,n-1);
    nw->right = tree(nw->right,n-1);
    return nw;
    }
}
node* mx(node * maxx)
{
    if(maxx == NULL)
        return NULL;
    while(maxx->right)
        maxx = maxx->right;

    return maxx;
}

node* minm(node * mini)
{
    if(mini == NULL)
        return NULL;
    while(mini->left)
        mini = mini->left;

    return mini;
}
void inorder(node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

#endif // FULLBTREE_H_INCLUDED
