#include<bits/stdc++.h>
using namespace std;
//Min diff= min(arr[i]- k) toh arr[ith] print
//therefore k ke sabse kareeb kon sa elemnt h.
int MinDifferenceofSortedArray(int arr[],int k)
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
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

    }
    if(abs(arr[l]-k)>=abs(arr[r]-k))
        return arr[r];
    else 
    return arr[l];
}      
int main()
{
    int arr[9]={1,2,5,6,7,9,11,14,19};
    cout<<MinDifferenceofSortedArray(arr,8)<<endl;
}

