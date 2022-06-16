#include<bits/stdc++.h>
using namespace std;
//Given an array , we need to tell what is the maxmim sum possible with subarray of size k
//Use sliding window.
int MaxSumSubArray(int arr[],int k)
{
    int n=11;
    int i=0,j=0;
    int sum=0;int mx=INT_MIN;
    while(j<n)
    {
        sum+=arr[j];
        if(j-i+1<k)
            j++;
        else if(j-i+1==k)
        {
            mx=max(mx,sum);
            sum=sum-arr[i];
            i++;
            j++;
        }
    }
    return mx;

}      
int main()
{
    int arr[11]={1,2,5,19,6,7,9,11,3,4,14};
    cout<<MaxSumSubArray(arr,3);
}
