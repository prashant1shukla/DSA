#include<bits/stdc++.h>
using namespace std;
//Good question.
//Nearly sorted array means the exact value for sorted array can be found on ith,ith-1,ith+1 positions.
int SearchinNearlySortedArray(int arr[],int k)
{
    int n=9;
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]==k)
            return mid;
        else if(mid-1>=l && arr[mid-1]==k)
            return mid-1;
        else if(mid+1<=r && arr[mid+1]==k)
            return mid+1;
        else if(arr[mid]>k)
            l=mid+1;
        else
            r=mid-1;
    }
    return -1;
}      
int main()
{
    int arr[9]={2, 1, 3, 5, 4, 7, 6, 8, 9};
    cout<<SearchinNearlySortedArray(arr,5)<<endl;
}

