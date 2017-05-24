#include"fullBTree.h"

using namespace std;

int arr[100];

void vertical(node *root, int c)
{
    if(!root)
        return;
    vertical(root->left, c-1);
    arr[c] += root->data;
    vertical(root->right, c+1);

}

int main()
{
    int n;
    cout<<"How many level u want: ";
    cin>>n;
    node *nd,*r;
    nd = tree(nd,n+1);
    vertical(nd,n);
    for(int i = 0;i<=2*n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
