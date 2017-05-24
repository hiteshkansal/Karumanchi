#include "fullBTree.h"
#include <stack>

void in(node *root)
{
    stack<node *> st;
    while(1)
    {
        while(root)
        {
            st.push(root);
            root = root->left;
        }
        if(st.empty())
            break;
        root = st.top();
        st.pop();
        cout<<root->data<<" ";
        root = root->right;
    }
}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    in(nd);
    return 0;
}
