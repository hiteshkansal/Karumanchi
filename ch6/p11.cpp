#include "fullBTree.h"
#include<queue>

int main()
{
    int n,cnt=0;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*tmp;
    nd = tree(nd,n+1);
    queue<node *> q;
    q.push(nd);
    q.push(NULL);
    while(!q.empty())
    {
        nd = q.front();
        q.pop();
        if(nd==NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
                cnt++;
            }
        }
        else
        {
            if(nd->left)
            q.push(nd->left);
            if(nd->right)
            q.push(nd->right);
        }
    }
    cout<<cnt;
    return 0;
}
