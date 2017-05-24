#include"fullBTree.h"
#include<stack>

void zigzag(node * root)
{
    node *temp;
    if(!root)
        return;
    stack<node *> s1,s2;
    s1.push(root);
    while(1)
    {
        if(s1.empty() && s2.empty())
            return;
        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";
            if(temp->left)
                s2.push(temp->left);
            if(temp->right)
                s2.push(temp->right);
        }
        while(!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";
            if(temp->right)
                s1.push(temp->right);
            if(temp->left)
                s1.push(temp->left);
        }
    }
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    zigzag(nd);
    return 0;
}
