#include<iostream>

using namespace std;

int edit_distance(char x[], int m, char y[], int n)
{
    int arr[m+1][n+1];
    int cd = 1, ci = 2, cr = 3;
    for(int i=1;i<=n;i++)
        arr[0][i] = i*ci;
    for(int i=1;i<=m;i++)
        arr[i][0] = i*cd;
    arr[0][0] = 0;

    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            int a,b,c;
            if(x[i-1] == y[j-1])
                arr[i][j] = arr[i-1][j-1];
            else
            {
                a=arr[i-1][j]+cd;
                b=arr[i][j-1]+ci;
                c=arr[i-1][j-1]+cr;
                arr[i][j] = min(a,min(b,c));
            }
        }

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
        return arr[m][n];
}

int main()
{
    char a[] = "hitu";
    char b[] = "jitu";
    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    cout<<edit_distance(a,m-1,b,n-1);
    return 0;
}
