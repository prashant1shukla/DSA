#include<bits/stdc++.h>
using namespace std;
//we will find index then we will call 2 binary searches. One will return -1 and the otehr will give our ans.
int BinarySearch(int arr[],int l1,int r1,int k)
{
    
    int l=l1,r=r1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<k)
            l=mid+1;
        else if(arr[mid]>k)
            r=mid-1;        
    }
    return -1;
}   
int FindElementinRoatedSortedArray(int arr[], int k)
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
    int a=BinarySearch(arr,ans,8,k);
    int b=BinarySearch(arr,0,ans,k);
   // cout<<a<<" "<<b;
    if(a!=-1)
        return a;
    else
        return b;

}   
int main()
{
    int arr[9]={18,22,25,1,3,5,10,14,16};
    cout<<FindElementinRoatedSortedArray(arr,14)<<endl;
}

