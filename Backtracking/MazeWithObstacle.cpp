#include<bits/stdc++.h>
using namespace std;
//given a 2D array, need to print all possible paths 
//we can only apply 2 opterations- do either right or go down.
//starting from (1,1) to move to (n,m)
//we need to check for every step whether there is an obstacle or not. if yes then stop 

// this is NOT backtracking, this is just STOPPING THE RECURSION.
void printingPathsWithObstacles(string p,bool maze[3][3], int r,int c)
{
    if(r==3-1 && c==3-1)
    {
        cout<<p<<endl;
        return;
    }
    if(maze[r][c]==false)
        return;
    
    if(r<3-1)
        printingPathsWithObstacles(p+'V',maze,r+1,c);

    if(c<3-1)
        printingPathsWithObstacles(p+'H',maze,r,c+1);
    

}
int main()
{
    string s="";
    bool maze[3][3] ={{true,true,true},{true,true,true},{true,false,true}};
    printingPathsWithObstacles(s,maze,0,0);
}