#include "fullBTree.h"
#include <stack>

node* in(node *root, node * nd)
{
    stack<node *> st;
    while(1)
    {
        while(root)
        {
            st.push(root);
            if(root == nd)
            {
                st.pop();
                if(root->right!=NULL&&!st.empty())
                    return root->right;

                if(root->right==NULL&&st.empty())
                    return NULL;

                if(root->right!=NULL&&st.empty())
                {
                    root=root->right;
                    while(root)
                    {
                        root = root->left;
                        if(!root->left)
                            break;
                    }
                    return root;
                }
                return st.top();
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
    fnd= nd;//->left->left;
    result = in(nd,fnd);
    if(result)
        cout<<"Inorder Succesor is: "<<result->data;
    else
        cout<<"No succesor";
    return 0;
}

