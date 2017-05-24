#include<iostream>
#include<string.h>
using namespace std;

int hsh(string p, int m)
{
    int hsh =0,q=101;
    for(int i=0; i<m; i++)
        hsh = (hsh*256+p[i])%q;
    return hsh;
}

int main()
{
    string t = "hitesh kansal";
    string p = "sh ka";
    int m = p.size();
    int n = t.size();
    int q=101,r,i,hashv=1;
    int phash = hsh(p,m);
    int shash = hsh(t,m);
    for(int i=0; i<m-1; i++)
        hashv=(hashv*256)%q;

    for(i=0; i<=n-m; i++)
    {
        if((shash==phash))
        {
            for(r=0; r<m; r++)
            {
                if(t[r+i]!=p[r])
                    break;
            }
            if(r==m)
            {
                cout<<"string matched at index: "<<i;
                break;
            }
        }
        if(i<n-m)
        {
            shash = (256*(shash-(hashv*t[i]))+t[i+m])%q;
            if(shash<0)
                shash+=q;
        }
    }
    return 0;
}
