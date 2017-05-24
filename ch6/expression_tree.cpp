#include<iostream>
#include<stdlib.h>
#include<stack>

using namespace std;

typedef struct treenode
{
    char data;
    struct treenode *left;
    struct treenode *right;
}node;

void inorder(node *p)
{
    if(p)
    {
        inorder(p->left);
        cout<<p->data<<" ";
        inorder(p->right);
    }
}

node * exptree(char post[],int sz)
{
    stack<node*> st;
    int i;
    for(i=0;i<sz;i++)
    {
        if(isalnum(post[i]))
        {
            node *nw = (node*)malloc(sizeof(node));
            if(!nw)
                {
                    cout<<"Memory Error."<<endl;
                    return NULL;
                }
            nw->data = post[i];
            nw->left = nw->right = NULL;
            st.push(nw);
        }
        else
        {
            node *op2 = st.top();
            st.pop();
            node *op1 = st.top();
            st.pop();
            node *nw = (node*)malloc(sizeof(node));
            if(!nw)
                {
                    cout<<"Memory Error."<<endl;
                    return NULL;
                }
            nw->data = post[i];
            nw->left = op1;
            nw->right = op2;
            st.push(nw);
        }
    }
    return st.top();
}

int main()
{
    node *root;
    char post[]= {'a','b','c','*','+','d','/'};
    int sz= sizeof(post)/sizeof(post[0]);
    root = exptree(post, sz);
    inorder(root);
    return 0;
}
