#include<bits/stdc++.h>
using namespace std;
//We need ton find position(index) in an INFIITE sorted array.
//Problem #1: high index kya maanu?
//intitailly high ko 1 lo, then (while(end<k)end=2*end) and also make start previous end.
//ans will lie between that new start and new end.
int PositionofElementinSortedArray(int arr[],int k)
{
    //int n=9;
    int l=0,r=1;
    int ans=-1;
    while(arr[r]<k)
    {
        l=r;
        r=2*r;
    }
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]==k)
            return mid;   
        else if(arr[mid]<k)
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

    }
    return ans;
}      
int main()
{
    int arr[9]={1,2,5,6,7,9,11,14,19};
    cout<<PositionofElementinSortedArray(arr,11)<<endl;
}

