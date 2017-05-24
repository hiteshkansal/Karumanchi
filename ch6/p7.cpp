#include "fullBTree.h"
#include<queue>


int main()
{
    queue<node *> q;
    int n,cnt=0;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*tmp;
    nd = tree(nd,n+1);
    q.push(nd);
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        cnt++;
        if(tmp->left)
            q.push(tmp->left);
        if(tmp->right)
            q.push(tmp->right);
    }
    cout<<cnt;
    return 0;
}

