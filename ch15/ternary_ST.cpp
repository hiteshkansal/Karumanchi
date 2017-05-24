#include<iostream>
#include<string.h>

using namespace std;

typedef struct TST
{
    char data;
    bool eos;
    struct TST *left;
    struct TST *eq;
    struct TST *right;
} TST;

TST* node(char c)
{
    TST *nw = new TST;
    nw->data = c;
    nw->left = nw->right = nw->eq = NULL;
    nw->eos = 0;
    return nw;
}

TST* insrt(TST *root, char *word)
{
    if(!word)
        return root;
    if(!root)
        root = node(*word);

    if(*word < root->data)
        root->left = insrt(root->left,word);
    else if(*word == root->data)
    {
        if(*(word+1))
        {
            root->eq = insrt(root->eq, word+1);
        }
        else
        {
            root->eos = 1;
            return root;
        }
    }
    else
        root->right = insrt(root->right, word);
    return root;
}

int serch(TST *root, char *w)
{
    if(!root)
    {
        return -1;
    }
    if(*w < root->data)
        return serch(root->left,w);
    else if(*w > root->data)
        return serch(root->right,w);
    else
    {
        if(root->eos && !*(w+1))
            return 1;
        return serch(root->eq,w+1);
    }
}

void display(TST *root, char word[], int i)
{
    if(!root)
        return;
    display(root->left,word,i);
    word[i] = root->data;
    if(root->eos==1)
    {
        for(int j=0;j<=i;j++)
            cout<<word[j];
        cout<<endl;
    }
    display(root->eq, word,i+1);
    display(root->right, word, i);
}

int main()
{
    TST *root = NULL;

    char *w1 = "boat";
    char *w2 = "bot";
    char *w3 = "boats";
    char *w4 = "bat";
    char *w5 = "jiu";
    char word[100];
    int i=0;
    root = insrt(root,w1);
    root = insrt(root,w2);
    root = insrt(root,w3);
    root = insrt(root,w4);
    root = insrt(root,w5);

    display(root,word,i);

    cout<<serch(root,w1);
    cout<<serch(root,w2);
    cout<<serch(root,"hitu");
    cout<<serch(root,w4);
    cout<<serch(root,w5);
    return 0;
}
/*
int main()
{
    char *w = "hello";
    char *t =w;
    cout<<*(++w);
}
*/
