#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

typedef struct treenode
{
    char data;
    struct treenode *left;
    struct treenode *right;
} node;

node * buildtr(char pre[], int *i)
{
    node * nw = (node*)malloc(sizeof(node));
    nw->data = pre[*i];
    nw->left = nw->right = NULL;
    if(sizeof(pre)==0)
    {
        free(nw);
        return NULL;
    }
    if(pre[*i] == 'l')
    return nw;

    *i =*i+1;
    nw->left = buildtr(pre,i);
    *i =*i+1;
    nw->right = buildtr(pre,i);
    return nw;
}
node* buildtr1(char post[], int *i)
{

    if(!sizeof(post))
        return NULL;
    node *nw = new node;
    nw->data = post[*i];
    nw->left = nw->right = NULL;

    if(post[*i] == 'l')
        return nw;
    *i = *i-1;
    nw->right = buildtr1(post,i);
    *i = *i-1;
    nw->left = buildtr1(post,i);
    return nw;
}

int main()
{
    node *root;
    char pre[] = {'i','i','l','l','i','l','l'};
    char post[] = {'l','l','i','l','l','i','i'};
    int i=0;
    int j = (sizeof(post)/sizeof(post[0]))-1;
    //root = buildtr(pre,&i);
    root = buildtr1(post,&j);
    cout<<root->left->data;
    return 0;
}
