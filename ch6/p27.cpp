#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct treenode
{
    char data;
    struct treenode *left;
    struct treenode *right;
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

int srch(char in[], int n, int m, char v)
{
    int i;
    for(i=n; i<=m; i++)
        if(in[i] == v)
            return i;
    return -1;
}

node* buildtree(char pre[], char in[], int ins, int ine)
{
    static int inp = 0;
    int index;
    node *nw = (node*)malloc(sizeof(node));
    nw->left = NULL;
    nw->right = NULL;
    if(ins>ine)
        return NULL;
    if(!nw)
    {
        cout<<"Memory full";
        return NULL;
    }
    nw->data = pre[inp];
    inp++;
    if(ins == ine)
        return nw;
    index = srch(in,ins,ine,nw->data);
    if(index < 0)
        return NULL;
    if((index > ins))
        nw->left = buildtree(pre,in,ins, index-1);
    if((index < ine))
        nw->right = buildtree(pre,in,index+1,ine);
    return nw;
}

int main()
{
    node *tr;
    char in[] = {'d','b','e','a','f','c'};
    char pre[] = {'a','b','d','e','f','c'};
    int len = sizeof(pre)/sizeof(pre[0]);
    tr = buildtree(pre,in,0,len-1);
    inorder(tr);
    return 0;
}
