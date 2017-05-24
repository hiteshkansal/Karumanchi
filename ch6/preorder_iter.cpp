#include "fullBTree.h"
#include <stack>
void pre(node *root)
{
    stack<node *> st;
    while(1)
    {
        while(root)
        {
            cout<<root->data<<" ";
            st.push(root);
            root = root->left;
        }
        if(st.empty())
            break;
        root = st.top();
        st.pop();
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
    pre(nd);
    return 0;
}
