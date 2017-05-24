#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> temp;

void median(int a[], int alo, int ahi, int b[], int blo, int bhi)
{
    int amid = alo + (ahi - alo)/2;
    int bmid = blo + (bhi - blo)/2;
    int amed = a[amid], bmed = b[bmid];
    if(ahi-alo + bhi-blo < 4)
    {
        int i=0;
        while(alo<=ahi){
        temp.push_back(a[alo]);
        alo++;
        i++;
        }
        while(blo<=bhi){
        temp.push_back(a[blo]);
        blo++;
        i++;
        }
        sort(temp.begin(),temp.end());
            cout<<(temp[1]+temp[2])/2;
    }

    else if(amed < bmed)
        median(a,amid,ahi,b,blo,bmid);

    else
        median(a,alo,amid,b,bmid,bhi);
}

int main()
{
    int a[] ={1,7,8,9,10};
    int b[] ={1,2,3,4,5};
    median(a,0,4,b,0,4);

    return 0;
}
