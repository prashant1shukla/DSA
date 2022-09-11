#include<bits/stdc++.h>
using namespace std;
//given a 2D array, need to print all possible paths 
//we can only apply 4 opterations- do either right or go down or go up or go left.
//starting from (1,1) to move to (n,m)
//we need to check for every step whether there is an obstacle or not. if yes then stop and then come back and then move somewhere else.

// this is BACKTRACKING, wehre we can go back and then apply new operations.
void PathsWithObsAllDirections(string p,bool maze[3][3], int r,int c,int path[3][3],int step)
{
    if(r==3-1 && c==3-1)
    {
        path[r][c]=step;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<path[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<p<<endl;
        return;
    }
    if(maze[r][c]==false)
        return;

    //doing changes
    maze[r][c]=false;
    path[r][c]=step;
    if(r<3-1)
        PathsWithObsAllDirections(p+'D',maze,r+1,c,path,step+1);

    if(c<3-1)
        PathsWithObsAllDirections(p+'R',maze,r,c+1,path,step+1);
    if(r>0)
        PathsWithObsAllDirections(p+'U',maze,r-1,c,path,step+1);

    if(c>0)
        PathsWithObsAllDirections(p+'L',maze,r,c-1,path,step+1);
    
    //Undoing changes ie Backtracking
    maze[r][c]=true;
    path[r][c]=0;
}
int main()
{
    string s="";
    int path[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    bool maze[3][3] ={{true,true,true},{true,true,true},{true,false,true}};
    PathsWithObsAllDirections(s,maze,0,0,path,1);
}