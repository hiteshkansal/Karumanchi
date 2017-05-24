#include<iostream>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *left, *right;
}node;

int max_leaf(node *root, int *mx)
{
    if(!root)
        return 0;
    int l, r;
    l = max_leaf(root->left, mx);
    r = max_leaf(root->right, mx);

    if((l+r+root->data) > *mx)
        *mx = l+r+root->data;
    return max(l,r)+root->data;
}

int main()
{
    // Let us construct a binary tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->right->right = newNode(9);
    root->right->right->left = newNode(10);
    int mx = -123;
    max_leaf(root,&mx);
    return 0;
}
