#include<iostream>
#include<map>

using namespace std;

typedef struct node{
    struct node *left;
    int data;
    char chr;
    struct node *right;
}node;

node* huffman(multimap<int,node*> m, int n)
{
    int sum=0;
    multimap<int, node*> :: iterator it;
    //for(int i=0;i<n-1;i++)
    while(m.size()!=1)
    {
        it = m.begin();
        node* temp = new node;
        temp->left = it->second;
        m.erase(m.begin());
        it = m.begin();
        temp->right = it->second;
        m.erase(m.begin());
        temp->data = temp->left->data + temp->right->data;
        m.insert({temp->data, temp});
        sum+=temp->data;
    }
    cout<<sum<<endl;
    return it->second;
}

void print(node *tree, int arr[], int top)
{
    if(tree->left)
    {
        arr[top]=0;
        print(tree->left,arr,top+1);
    }
    if(tree->right)
    {
        arr[top]=1;
        print(tree->right,arr,top+1);
    }
    if(!(tree->left) && !(tree->right))
    {
        cout<<tree->chr<<": ";
        for(int i=0;i<top;i++)
            cout<<arr[i];
        cout<<endl;
    }
}
int main()
{
    char c[] = {'a','b','c','d','e','f'};
    int freq[] = {12,2,7,13,14,85};
    int n = sizeof(c)/sizeof(c[0]);
    multimap<int, node*> m;
    node* root;
    int arr[10];
    for(int i=0; i<n; i++)
    {
        node *temp = new node;
        temp->left = temp->right = NULL;
        temp->data = freq[i];
        temp->chr = c[i];
        m.insert({freq[i], temp});
    }
/*    multimap<int,node*> :: iterator it = m.begin();

    for(int i=0;i<n;i++)
    {
        cout<<it->first<<" "<<(char)(it->second->data)<<endl;
        it++;
    }
  */  root = huffman(m,n);
  print(root,arr,0);
    return 0;
}
