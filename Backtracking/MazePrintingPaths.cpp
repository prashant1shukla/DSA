#include<bits/stdc++.h>
using namespace std;
//given a 2D array, need to print all possible paths 
//we can only apply 2 opteration- do either right or go down.
//starting from (1,1) to move to (n,m)
void printingPaths(string p, int r,int c)
{
    if(r==1 && c==1)
    {
        cout<<p<<endl;
        return;
    }
    if(r>1)
    {
        printingPaths(p+'D',r-1,c);
    } 
    if(c>1)
    {
        printingPaths(p+'R',r,c-1);
    }

}
int main()
{
    string s="";
    printingPaths(s,3,3);
}