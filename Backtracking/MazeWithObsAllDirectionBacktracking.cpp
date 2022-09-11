#include<bits/stdc++.h>
using namespace std;
//given a 2D array, need to print all possible paths 
//we can only apply 4 opterations- do either right or go down or go up or go left.
//starting from (1,1) to move to (n,m)
//we need to check for every step whether there is an obstacle or not. if yes then stop and then come back and then move somewhere else.

// this is BACKTRACKING, wehre we can go back and then apply new operations.
void PathsWithObsAllDirections(string p,bool maze[3][3], int r,int c)
{
    if(r==3-1 && c==3-1)
    {
        cout<<p<<endl;
        return;
    }
    if(maze[r][c]==false)
        return;

    //doing changes
    maze[r][c]=false;
    
    if(r<3-1)
        PathsWithObsAllDirections(p+'D',maze,r+1,c);

    if(c<3-1)
        PathsWithObsAllDirections(p+'R',maze,r,c+1);
    if(r>0)
        PathsWithObsAllDirections(p+'U',maze,r-1,c);

    if(c>0)
        PathsWithObsAllDirections(p+'L',maze,r,c-1);
    
    //Undoing changes ie Backtracking
    maze[r][c]=true;

}
int main()
{
    string s="";
    bool maze[3][3] ={{true,true,true},{true,true,true},{true,false,true}};
    PathsWithObsAllDirections(s,maze,0,0);
}