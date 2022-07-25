#include<bits/stdc++.h>
using namespace std; 
//Given an array with 3 flags(0,1,2), arrange them in such a way that all red(0s) occu~ kadane's algorithm

void sortColors(int nums[]) 
{
        int l=0;int mid=0;int r=6-1;
        for(int i=0;i<6;i++)
        {
            if(nums[mid]==1)
                mid++;
            else if(nums[mid]==0)
            {
                swap(nums[mid],nums[l]);
                mid++;l++;
            }
            else
            { 
                swap(nums[r],nums[mid]);r--;
            }
        }
}
int main()
{
    int nums[]={2,0,2,1,1,0};
    sortColors(nums);
    for(int i=0;i<6;i++)
        cout<<nums[i]<<" ";
}
    