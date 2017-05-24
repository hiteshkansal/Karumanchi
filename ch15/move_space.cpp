#include<iostream>
#include<string.h>

using namespace std;

void move_space(char s[], int n)
{
    int i=n-1,j;
    for(j=n-1;j>=0;j--)
    {
        if(!isspace(s[j]))
        {
           swap(s[i],s[j]);
           i--;
        }
    }
}

int main()
{
    char s[] = "hello hitesh kansal";
    int n = strlen(s);
    move_space(s,n);
    cout<<s;
    return 0;
}
