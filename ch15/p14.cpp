#include<iostream>
#include<string.h>

using namespace std;

bool match(char mat[5][5], char ptr[], int **used, int x, int y,int nrow, int ncol, int level)
{
    if(strlen(ptr)>nrow*ncol)
        return false;
    if(strlen(ptr)==level)
        return true;
    if(nrow==x || ncol==y)
        return false;
    if(used[x][y])
        return false;
    if(mat[x][y]!=ptr[level] && level==0)
    {
        if(x < (nrow-1))
            return match(mat,ptr,used,x+1,y,nrow,ncol,level);
        else if(y < (ncol-1))
            return match(mat,ptr,used,0,y+1,nrow,ncol,level);
        else
            return false;
    }
    else if(mat[x][y]==ptr[level])
    {
        bool res;
        used[x][y] =1;
        res = (x>0 ? match(mat,ptr,used,x-1,y,nrow,ncol,level+1): false) ||
            (res =x<(nrow-1)? match(mat,ptr,used,x+1,y,nrow,ncol,level+1): false) ||
            (res =y>0 ? match(mat,ptr,used,x,y-1,nrow,ncol,level+1): false) ||
            (res =y<(ncol-1)? match(mat,ptr,used,x,y+1,nrow,ncol,level+1): false) ||
            (res =x<(nrow-1) && (y<ncol-1) ? match(mat,ptr,used,x+1,y+1,nrow,ncol,level+1): false) ||
            (res =x<(nrow-1) && y>0 ? match(mat,ptr,used,x+1,y-1,nrow,ncol,level+1): false) ||
            (res =x>0 && y<(ncol-1)? match(mat,ptr,used,x-1,y+1,nrow,ncol,level+1): false) ||
            (res =x>0 && y>0 ? match(mat,ptr,used,x-1,y-1,nrow,ncol,level+1): false);
        used[x][y]=0;
        return res;
    }
    else
        return false;
}

int main()
{
    char mat[][5] = {{'A','C','P','R','C'},{'X','S','O','P','C'},{'V','O','V','N','I'},
                    {'W','G','F','M','N'},{'Q','A','T','I','T'}};
    int **used = new int*[5];
    for(int i=0;i<5;i++)
        used[i] = new int[5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            used[i][j]=0;
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    char ptr[] = "MICROSOFT";
    int level=0;
    cout<<match(mat,ptr,used,0,0,5,5,level);
    return 0;
}
