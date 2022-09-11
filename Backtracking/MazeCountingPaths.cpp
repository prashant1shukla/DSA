#include<bits/stdc++.h>
using namespace std;
//given a 2D array, need to return the count of all possible paths 
//we can only apply 2 opteration- do either right or go left.
//starting from (1,1) to move to (n,m)
int countPaths(int r,int c)
{
    if(r==1 || c==1)
        return 1;
    int left=countPaths(r-1,c);
    int right=countPaths(r,c-1);
    return left+right; 
}
int main()
{
    cout<<countPaths(3,3)<<endl;
}