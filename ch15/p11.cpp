#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

void combi(int d, int s, char *word, char* a, int n)
{
    for(int i=s; i<n; i++)
    {
        word[d] = a[i];
        word[d+1] = '\0';
        cout<<word<<endl;
        if(i<n-1)
            combi(d+1,i+1,word,a,n);
    }
}

void combi_r(int d, int s, char *word, char* a, int r, int n)
{
    if(d==r)
        cout<<word<<endl;

    for(int i=s; i<n; i++)
    {
        word[d] = a[i];
        word[d+1] = '\0';
        combi_r(d+1,i+1,word,a,r,n);
    }
}

int main()
{
    char *a = "abcdef";
        int n = strlen(a);
    int r=3;
    char *word  = new char[strlen(a)];
    //combi(0,0,word,a,n);
    combi_r(0,0,word,a,r,n);
    return 0;
}
