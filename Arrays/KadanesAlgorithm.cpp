#include<bits/stdc++.h>
using namespace std; 
//return the maximum sum of any subarray amongsts the given array ~ kadane's algorithm

int KadanesAlgorithm(int arr[])
{
    int mx=INT_MIN;
    int sum=0;
    for(int i=0;i<9;i++)
    {
        sum+=arr[i];
        mx=max(mx,sum);
        if(sum<0)
            sum=0;
    }
    return mx;
}
int main()
{
    int nums[]={-2,1,-3,4,-1,2,1,-5,4};
    cout<<KadanesAlgorithm(nums);
}
    