#include<iostream>
#include<string.h>

using namespace std;

void permute(char *s,int i, int n)
{
    if(n-1==i)
        cout<<s<<endl;
    else
    {
        for(int k =i;k<n;k++)
        {
            swap(s[i],s[k]);
            permute(s,i+1,n);
            swap(s[i],s[k]);
        }
    }
}

int main()
{
    char s[] = "abc";
    int n = strlen(s);
    permute(s,0,n);
    return 0;
}
