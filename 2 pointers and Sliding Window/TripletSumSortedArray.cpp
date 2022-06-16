#include<bits/stdc++.h>
using namespace std;
//Given an sorted array , we need to tell whether there is triplet whose sum is equal to k.
//Use 2 pointer approach and pass it through another function for triplet. OK
bool PairSumSortedArray(int arr[],int l,int r,int k)
{
    while(l<r)
    {
        if(arr[l]+arr[r]==k)
            return true;
        else if(arr[l]+arr[r]<k)
            l++;
        else if(arr[l]+arr[r]>k)
            r--;
    }
    return false;

}      
bool PairSumSortedArray(int arr[],int k)
{
    int n=9;
    for(int i=0;i<n;i++)
    {
        if(PairSumSortedArray(arr,i+1,n-1,k-arr[i]))
            return true;
    }
    return false;
}
int main()
{
    int arr[9]={1,2,5,6,7,9,11,14,19};
    if(PairSumSortedArray(arr,18))
        cout<<"Yes";
    else
        cout<<"No";
}

