#include "fullBTree.h"
#include <queue>
/*
1 2 3 4 5 6 7
*/
int main()
{
    node *root;
    int odd = 0, even = 0,level = 0;
    root = tree(root,3);
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if(temp==NULL)
        {
            level++;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            if(level&1)
                odd+=temp->data;
            else
                even+=temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    cout<<odd-even;
    return 0;
}
