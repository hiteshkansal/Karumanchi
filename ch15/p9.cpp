#include<iostream>
#include<string.h>

using namespace std;

char* reverseword(char str[],int s, int n)
{
    while(s<n)
    {
        str[s]^=str[n];
        str[n]^=str[s];
        str[s]^=str[n];
        s++;
        n--;
    }
    return str;
}

char* reverse(char s[])
{
    int n = strlen(s);
    char *temp = s;
    int i=0,j=0;
    while(*temp)
    {
        if((*temp)== ' ')
        {
            s = reverseword(s,i,j-1);
            i=j+1;
            temp = s+j;
        }
        temp++;
        j++;
    }
    if(*temp == '\0')
        s = reverseword(s,i,j-1);
    return reverseword(s,0,n-1);
}

int main()
{
    char s[] = "hello how are you";
    cout<<reverse(s);
    return 0;
}
