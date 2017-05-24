#include "fullBTree.h"
#include <stack>
node* pre(node *root, node* nd)
{
    stack<node *> st;
    while(1)
    {
        while(root)
        {
            st.push(root);
            if(root == nd && root->left!=NULL)
                return root->left;
            if(root == nd && root->right!=NULL && root->left==NULL)
                return root->right;
            if(root == nd && root->right==NULL && root->left==NULL)
            {
                st.pop();
                if(st.empty())
                    return NULL;
                return (st.top()->right);
            }
            root = root->left;
        }
        if(st.empty())
            return NULL;

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
    node *nd,*fnd,*result;
    nd = tree(nd,n+1);
    fnd= nd->left->right->right;
    result = pre(nd,fnd);
    if(result)
    cout<<"Succesor is: "<<result->data;
    else
    cout<<"No succesor";
    return 0;
}

