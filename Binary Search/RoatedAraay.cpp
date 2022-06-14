#include<bits/stdc++.h>
using namespace std;
int RotatedArray(int arr[])
{
    int n=9;
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]>arr[n-1])
            l=mid+1;
        else if(arr[mid]<arr[n-1])
        {   
            ans=mid;
            r=mid-1;        
        }
    }
    return ans;
}   
int main()
{
    int arr[9]={18,22,25,1,3,5,10,14,16};
    cout<<RotatedArray(arr)<<endl;
}

