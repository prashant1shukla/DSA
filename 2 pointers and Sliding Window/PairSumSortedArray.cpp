#include<bits/stdc++.h>
using namespace std;
//Given an sorted array , we need to tell whether there is pair whose sum is equal to k
//Use 2 pointer approach.
bool PairSumSortedArray(int arr[],int k)
{
    int l=0,r=9-1;
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
int main()
{
    int arr[9]={1,2,5,6,7,9,11,14,19};
    if(PairSumSortedArray(arr,4))
        cout<<"Yes";
    else
        cout<<"No";
}

