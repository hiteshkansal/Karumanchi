#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;

void minwindow(char in[], char ch[])
{
    int start = -1,finish =-1,j=0,cnt=0,minwin = INT_MAX;
    int chlen = strlen(ch), inlen = strlen(in);
    int shdfnd[256]={0}, hsfnd[256]={0};
    for(int i=0;i<chlen;i++)
        shdfnd[ch[i]]++;
    int i;
    for(i=0;i<inlen;i++)
    {
        if(!shdfnd[in[i]])
            continue;
        hsfnd[in[i]]++;
        if(shdfnd[in[i]]>=hsfnd[in[i]])
            cnt++;
        if(cnt==chlen)
        {
            while(shdfnd[in[j]]==0 || hsfnd[in[j]]>shdfnd[in[j]])
            {
                if(hsfnd[in[j]]>shdfnd[in[j]])
                    hsfnd[in[j]]--;
                j++;
            }
            if(minwin > i-j+1)
            {
                minwin = i-j+1;
                start=j;
                finish =i;
            }
        }
    }
    if(start==-1 || finish==-1)
        cout<<"string not present.";
    else
        cout<<start<<" "<<finish<<" "<<minwin;
}

int main()
{
    char in[] = "This is a test string";
   // char in[] = "abcd";
    char ch[] = "tsir";
    minwindow(in,ch);
    return 0;
}
