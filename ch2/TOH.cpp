#include<iostream>
#include<vector>
using namespace std;
/*
void TOH(int n,char a, char b, char c)
{
    if(n==1)
        cout<<a<<"---->"<<c<<endl;
    else
    {
        TOH(n-1,a,c,b);
        cout<<a<<"---->"<<c<<endl;
        TOH(n-1,b,a,c);
    }
}

int main()
{
    cout<<"Enter disk: ";
    int n;
    cin>>n;
    TOH(n,'A','B','C');
    return 0;
}

void Hanoi4(int nDisks, char source, char intermed1, char intermed2, char dest)
{
    if ( nDisks == 1 )
        cout << source << " --> " << dest << endl;
    else if ( nDisks == 2 )
    {
        cout << source << " --> " << intermed1 << endl;
        cout << source << " --> " << dest << endl;
        cout << intermed1 << " --> " << dest << endl;
    }
    else
    {
        Hanoi4(nDisks - 2, source, intermed2, dest, intermed1);
        cout << source << " --> " << intermed2 << endl;
        cout << source << " --> " << dest << endl;
        cout << intermed2 << " --> " << dest << endl;
        Hanoi4(nDisks - 2, intermed1, source, intermed2, dest);
    }
}

int main()
{
    Hanoi4(3, 'A', 'B', 'C', 'D');

    return 0;
}
*/
void move(int n, int source, int dest, vector <int> free_peg)
{
    int p, middle, g;

    if (n==1)
        cout<<source<<"---->"<<dest<<endl;
    else
    {
        if(free_peg.size()>=2)
            p = n/2;
        else
            p = n-1;

        //Move top "p" disks from peg 1 to peg i
        middle = free_peg.back();
        free_peg.pop_back();
        free_peg.push_back(dest);
        move(p, source, middle,free_peg);
        //Move "n - p " disks from peg 1 to another peg
        free_peg.pop_back();
        move(n - p, source, dest, free_peg);
        //Move p from current peg to the final peg
        free_peg.push_back(source);
        move(p, middle, dest, free_peg);
    }
}
int main()
{
    int k,n;
    cout<<"Enter tower & disks: ";
    cin>>k>>n;
    vector <int> free_peg;
    for(int i=2; i<k; i++)
    {
        free_peg.push_back(i);
    }
    move(n,1,k,free_peg);
    return 0;
}
