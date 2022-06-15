#include<bits/stdc++.h>
using namespace std;
//Floor means element just lesser than or equal to x.
int Floorinsortedarray(int arr[],int k)
{
    int n=9;
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]==k)
            return arr[mid];
        else if(arr[mid]<k)
        {
            ans=arr[mid];
            l=mid+1;
        }
        else
            r=mid-1;

    }
    return ans;
}      
int main()
{
    int arr[9]={1,2,5,6,7,9,11,14,19};
    cout<<Floorinsortedarray(arr,8)<<endl;
}

