//#include "bst.h"
#include "fullBTree.h"
#include<time.h>
using namespace std;

int isbst(node * root)
{
    if(!root)
        return 1;
    if(root->left!=NULL && (mx(root->left)->data) > root->data)
        return 0;
    if(root->right!=NULL && (minm(root->right)->data) < root->data)
        return 0;
    if(isbst(root->left) && isbst(root->right))
        return 1;

    return 0;
}

int main()
{
    int r,n=2;
//    node *root=NULL;
    node *root = tree(root,n+1);
    srand(time(0));
/*    for(int i=0; i<6; i++)
    {
        r= rand()%100+1;
        root = insrt(root,r);
    }

    root = insrt(root,4);
    root = insrt(root,12);
    root = insrt(root,1);
    root = insrt(root,67);
    root = insrt(root,9);
    root = insrt(root,44);
*/
    inorder(root);
    if(isbst(root))
    cout<<"\nYes!! BST";
    else
    cout<<"NOT A BST";

    return 0;
}
