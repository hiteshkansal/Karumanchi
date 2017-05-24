#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct bsttree
{
    struct bsttree *left;
    int data;
    struct bsttree *right;
} node;

void inorder(node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}
void pre(node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        pre(p->left);
        pre(p->right);
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

node * insrt(node *root, int v)
{
    if(root == NULL)
    {
        root = (node*)malloc(sizeof(node));
        if(!root)
            return NULL;
        root->data = v;
        root->left = root->right =NULL;
    }
    else
    {
        if(v < (root->data))
            root->left = insrt(root->left, v);
        else if(v > (root->data))
            root->right = insrt(root->right, v);
    }
    return root;
}

node* fnd(node *root, int v)
{
    if(root == NULL)
        return NULL;

    if(v < (root->data))
        return fnd(root->left, v);
    else if(v > (root->data))
        return fnd(root->right, v);

        return root;
}



#endif // BST_H_INCLUDED
