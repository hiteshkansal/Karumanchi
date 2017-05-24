#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct bsttree
{
    int data;
    struct bsttree *left;
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

node* insrt(node *root, int v)
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

node* delet(node *root, int v)
{
    node *del;
    if(root == NULL)
        return NULL;

    else if(v < root->data)
        root->left = delet(root->left,v);

    else if(v > root->data)
        root->right = delet(root->right, v);

    else
    {
        if((root->left) && (root->right))
        {
            del = mx(root->left);
            root->data = del->data;
            root->left = delet(root->left, root->data);
        }
        else
        {
            del = root;
            if(del->left == NULL)
                root = root->right;
            if(del->right == NULL && root)
                root = root->left;
            free(del);
        }
    }
    return root;
}

int main()
{
    int r=0,x;
    node *root = NULL,*temp;
    /*srand(time(0));
    for(int i=0; i<6; i++)
    {
        x=r;
        r= rand()%100+1;
        root = insrt(root,r);
    }
    */
    root = insrt(root,4);
    root = insrt(root,12);
    root = insrt(root,1);
    root = insrt(root,67);
    root = insrt(root,9);
    root = insrt(root,44);

    inorder(root);
//    cout<<"R is: "<<r<<endl;
    //temp = fnd(root,12);
    // cout<<temp->data;
    root =  delet(root,12);
    // temp = mx(root->right->left);
    // cout<<temp->data;
    inorder(root);
    return 0;
}
