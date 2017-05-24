#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct gentree
{
    int data;
    struct gentree *first;
    struct gentree *nextsibling;
}gtree;

gtree* create(int a)
{
    gtree * nw=(gtree*)malloc(sizeof(gtree));
    if(!nw)
    {
        cout<<"No Memory"<<endl;
        return NULL;
    }
    else
    {
        nw->data = a;
        nw->first = NULL;
        nw->nextsibling = NULL;
        return nw;
    }
}
/*
gtree* findroot(gtree *root,gtree *n)
{
    gtree* temp;
    if(!root)
    return NULL;

    if(root->first==n)
    return root;
    if(root->first || root->nextsibling)
    {
            if(root->nextsibling == n || root->first == n)
            return root;
            findroot(root->first,n);
            findroot(root->nextsibling,n);
    }
    return NULL;
}
*/
int main()
{
    gtree *root,*temp2,*temp;
    root = create(1);

    root->first = create(2);
    temp2 = root->first;
    for(int i=0;i<3;i++)
    {
        temp2->nextsibling = create(i+3);
        temp2 = temp2->nextsibling;
    }
    temp2->first = create(6);
    temp = findroot(root,temp2->first);
    cout<<temp->data;
    return 0;
}
