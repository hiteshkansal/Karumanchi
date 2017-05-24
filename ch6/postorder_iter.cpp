#include "fullBTree.h"
#include <stack>

void post(node *root)
{
    stack<node *> st;
    while(1)
    {
        if(root)
        {
            st.push(root);
            root = root->left;
        }
        else
        {
            if((st.top())->right==NULL)
            {
                root = st.top();
                st.pop();
                cout<<root->data<<" ";
                while(root==(st.top())->right)
                {
                    cout<<(st.top())->data<<" ";
                    root=st.top();
                    st.pop();
                    if(st.empty())
                        return;
                }
            }
            if(!st.empty())
                root=(st.top())->right;
            else
                root=NULL;
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
    post(nd);
    return 0;
}
