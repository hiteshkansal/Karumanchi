#include "fullBTree.h"
#include <queue>

node * insertnode(node *root)
{
    queue<node *> q;
    node *nw, *temp;
    nw = create();
    if(!root){
        root = nw;
        return root;
        }

    q.push(root);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left)
            q.push(temp->left);
        else
        {
            temp->left=nw;
            return root;
        }

        if(temp->right)
            q.push(temp->right);
        else
        {
            temp->right=nw;
            return root;
        }
    }
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*r;
    nd = tree(nd,n+1);
    nd = insertnode(nd);
    cout<<nd->left->left->left->data;   //for n==2 only
    return 0;
}
