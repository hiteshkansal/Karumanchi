#include<iostream>
#include<string.h>

using namespace std;

//Not printing correctly...

int lcs(char *X, char *Y, int m, int n)
{
    int L[m+1][n+1];
    int i, j,k=0;
    /*int flag[n+1];
    for(i=0; i<n+1; i++)
        flag[i]=1;
    cout<<"LCS is: ";
*/    for (i=0; i<=m; i++)
    {
       // k=1;
        for (j=0; j<=n; j++)
        {
            if (i==0 || j==0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
            {
  /*              if(k && flag[j-1])
                {
                    for(int l=1; l<j; l++)
                        flag[j-l]=0;
                    cout<<X[i-1];
                    k=0;
                }
    */            L[i][j] = L[i-1][j-1] + 1;
            }
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    cout<<"Length is: ";
    return L[m][n];
}

int main()
{
    char X[] = "BANANA";
    char Y[] = "KANANA";
    int m = strlen(X);
    int n = strlen(Y);
  /*  if(m<=n)
        cout<<lcs(X,Y,m,n);
    else
        cout<<lcs(Y,X,n,m);
    */
    cout<<lcs(X,Y,m,n);
    return 0;
}
