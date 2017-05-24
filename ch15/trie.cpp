#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct trie
{
    char data;
    bool end_string;
    struct trie *child[26];
} trie;

int search1(trie *root, char *word)
{
    if(!root)
        return -1;
    if(!*(word+1))
    {
        if(root->end_string ==1)
            return 1;
        else
            return -1;
    }
    if(root->data == *word )
        return search1(root->child[*(word+1)-97],word+1);
    else
        return -1;
}

trie* node(char c)
{
    trie *root = new trie;
    root->data = c;
    for(int i=0; i<26; i++)
        root->child[i] = NULL;
    return root;
}
trie* insrt(trie *root, char *word)
{
    if(!*word)
        return root;
    if(!root)
    {
        root = node(*word);
        if(!*(word+1))
            root->end_string = 1;
        else
        {
            root->end_string =0;
            root->child[*(word+1)-97] = insrt(root->child[*(word+1)-97],word+1);
        }
        return root;
    }
    else
        root->child[*(word+1)-97] = insrt(root->child[*(word+1)-97],word+1);
    return root;
}
int main()
{
    trie *head = node('$');
    head->end_string = 0;
    char *word = "hitesh";
    head->child[*word-97] = insrt(head->child[*word-97], word);
    char *word1= "hitu";
    head->child[*word1-97] = insrt(head->child[*word1-97], word1);
    char *w = "hitt";
    head->child[*w-97] = insrt(head->child[*w-97], w);

    char dd[10];
    cin>>dd;
    cout<<search1(head->child[dd[0]-97],dd);

    for(int i=0; head->end_string!=1; i++)
    {
        head= head->child[*(word1+i)-97];
        cout<<head->data<<head->end_string<<endl;
    }
    return 0;
}
