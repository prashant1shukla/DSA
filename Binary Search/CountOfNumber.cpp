#include<bits/stdc++.h>
using namespace std;
int FirstOccourance(int arr[],int k)
{
    int n=9;
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]==k)
        {
            ans=mid;
            r=mid-1;
        }
        else if(arr[mid]>k)
            r=mid-1;
        else
            l=mid+1;
        
    }
    return ans;

}   
int LastOccourance(int arr[],int k)
{
    int n=9;
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]==k)
        {
            ans=mid;
            l=mid+1;
        }
        else if(arr[mid]>k)
            r=mid-1;
        else
            l=mid+1;
    }
    return ans;
} 
int Count(int arr[],int k)
{
    return LastOccourance(arr,10)-FirstOccourance(arr,10)+1;
}
int main()
{
    int arr[9]={1,3,5,10,10,10,10,14,16};
    cout<<Count(arr,10)<<endl;
   
}

