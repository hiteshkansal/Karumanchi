#include"bst.h"

void add_value(node *root, int *sum)
{
    if(!root)
        return;
    add_value(root->right, sum);
    *sum = *sum+root->data;
    root->data = *sum;
    add_value(root->left, sum);
}

int main()
{
    node *root = NULL;
    int sum = 0;
    root = insrt(root,10);
    root = insrt(root,8);
    root = insrt(root,15);
    root = insrt(root,6);
    root = insrt(root,9);
    root = insrt(root,13);
    root = insrt(root,19);
    inorder(root);
    cout<<endl;
    add_value(root, &sum);
    inorder(root);
    return 0;
}
