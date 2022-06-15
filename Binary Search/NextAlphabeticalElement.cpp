#include<bits/stdc++.h>
using namespace std;
//Next ggreater aphabet elementin a sorted array for char.
char NextAlphabetinsortedarray(char arr[],char k)
{
    int n=9;
    int l=0,r=n-1;
    char ans='-1';
    while(l<=r)
    {
        int mid=l+((r-l)/2);
        if(arr[mid]==k)
            return arr[mid+1];   //as next grtr is only asked not ceil.
        else if(arr[mid]<k)
        {
            // ans=arr[mid];
            l=mid+1;
        }
        else
        {
            ans=arr[mid];
            r=mid-1;
        }

    }
    return ans;
}      
int main()
{
    char arr[9]={'a','b','c','d','e','f','g','h','i'};
    cout<<NextAlphabetinsortedarray(arr,'e')<<endl;
}

