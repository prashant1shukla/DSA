#include<bits/stdc++.h>
using namespace std;
//given a 2D array, need to print all possible paths 
//we can only apply 3 opterations- do either right or go down or go in diagonally 
//starting from (1,1) to move to (n,m)
void printingPathsWithDiagonals(string p, int r,int c)
{
    if(r==1 && c==1)
    {
        cout<<p<<endl;
        return;
    }
    if(r>1 && c>1)
        printingPathsWithDiagonals(p+'D',r-1,c-1);
    
    if(r>1)
        printingPathsWithDiagonals(p+'V',r-1,c);

    if(c>1)
        printingPathsWithDiagonals(p+'H',r,c-1);
}
int main()
{
    string s="";
    printingPathsWithDiagonals(s,3,3);
}