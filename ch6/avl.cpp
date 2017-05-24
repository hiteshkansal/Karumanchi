#include<iostream>
#include<stdlib.h>

using namespace std;
typedef struct avlnode
{
    int data;
    int height;
    struct avlnode *left;
    struct avlnode *right;
}avl;

void preorder(avl *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

int hight(avl* root)
{
    if(!root)
        return -1;
    else
        return root->height;
}

avl* LL(avl *node)
{
    avl *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    node->height = max(hight(node->left),hight(node->right))+1;
    temp->height = max(hight(temp->left), node->height)+1;
    return temp;
}

avl* RR(avl *node)
{
    avl *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    node->height = max(hight(node->left),hight(node->right))+1;
    temp->height = max(hight(temp->right), node->height)+1;
    return temp;
}

avl* LR(avl *node)
{
    node->left = RR(node->left);
    return LL(node);
}

avl* RL(avl *node)
{
    node->right = LL(node->right);
    return RR(node);
}

avl* insrt(avl* root, int val)
{
    if(!root)
    {
        root = (avl*)malloc(sizeof(avl));
        if(!root)
            return NULL;
        else
        {
            root->data = val;
            root->height = 0;
            root->left = root->right = NULL;
        }
    }
    else if(root->data > val)
    {
        root->left = insrt(root->left,val);
        if(hight(root->left) - hight(root->right) == 2)
        {
            //cout<<"left height: "<<hight(root->left) - hight(root->right)<<endl;
            if(val < root->left->data)
                root = LL(root);
            else
                root = LR(root);
        }
    }
    else if(root->data < val)
    {
        root->right = insrt(root->right,val);
        if(hight(root->right) - hight(root->left) == 2)
        {
            //cout<<"right height: "<<hight(root->right) - hight(root->left)<<endl;
            if(val > root->right->data)
                root = RR(root);
            else
                root = RL(root);
        }
    }
    root->height = max(hight(root->left),hight(root->right))+1;
    //cout<<root->height<<endl;
    return root;
}

int main()
{
    avl *root = NULL;
    root = insrt(root,4);
    root = insrt(root,1);
    root = insrt(root,12);
    root = insrt(root,9);
    root = insrt(root,67);
    root = insrt(root,44);
    root = insrt(root,55);
    root = insrt(root,0);
    preorder(root);
    return 0;
}
