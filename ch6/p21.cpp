#include "fullBTree.h"

/*
2
1 2 3 4 5 6 7
*/
int sum(node* root,int sum1)
{
    if(!root && sum1 ==0)
        return 1;
    else if(!root)
        return 0;
    sum1-=root->data;
    if(sum1==0)
        return 1;
    else
            return sum(root->left,sum1)|| sum(root->right,sum1);
}


int main()
{
    int n,sum1,flag=0;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd;
    nd = tree(nd,n+1);
    cout<<"Enter sum: ";
    cin>>sum1;
    flag = sum(nd,sum1);
    if(flag)
        cout<<"Yes";
    else
        cout<<"NO";
    return 0;
}

