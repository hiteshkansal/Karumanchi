#include<iostream>
#include<float.h>
using namespace std;

float sum(int i, int j, float f[])
{
    float total=0;
    for(int k=i;k<=j;k++)
        total+=f[k];
    return total;
}

float obst(float f[], int n)
{
    float tree[n+1][n+1];

    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            tree[i][j] = 0;

    for(int i=1;i<=n;i++)
        tree[i][i] = f[i-1];

    for(int l=2;l<=n;l++)
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            float temp, min = FLT_MAX;
            for(int r=i;r<=j;r++)
            {
                temp = tree[i][r-1] + tree[r+1][j];
                if(min > temp)
                    min = temp;
            }
            tree[i][j] = min + sum(i-1,j-1,f);
        }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<tree[i][j]<<" ";
        cout<<endl;
    }
    return tree[1][n];
}

int main()
{
    //int a[] = {3,12,21,32,35};
    float f[] = {0.22,0.18,0.20, 0.05, 0.25,0.02, 0.08};
    //float f[] = {0.2,0.14,0.16,0.23,0.27};
    int n = sizeof(f)/sizeof(f[0]);
    cout<<obst(f,n);
    return 0;
}
