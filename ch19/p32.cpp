#include<iostream>
#include "adlmat_graph.h"
using namespace std;
extern int ver;
/*
4 5
0 1 2
1 3 2
3 0 -1
3 2 -4
0 2 1
*/
void all_pair_shortest_path(int **c,int n)
{
    int a[ver][ver];

    for(int i=0;i<ver;i++)
        for(int j=0;j<ver;j++)
        a[i][j] = c[i][j];

    for(int i=0;i<ver;i++)
        a[i][i] = 0;
        cout<<endl;

    for(int k=0;k<ver;k++)
    {
        for(int i=0;i<ver;i++)
        {
            for(int j=0;j<ver;j++)
            {
                if(a[i][k]+a[k][j] < a[i][j])
                    a[i][j] = a[i][k] + a[k][j];
            }
        }
    }
    for(int i=0;i<ver;i++)
    {
        for(int j=0;j<ver;j++)
        {
         //   if(a[i][j]==1000 || a[i][j] == 999)   //What happening? No idea!!!
         //       cout<<"INF ";
         //   else
                cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    graph *gr;
    gr = create();
    all_pair_shortest_path(gr->adj,ver);
    return 0;
}
