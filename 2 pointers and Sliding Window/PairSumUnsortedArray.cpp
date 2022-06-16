#include<bits/stdc++.h>
using namespace std;
//Given an unsorted array , we need to tell whether there is pair whose sum is equal to k
//Use hashing (set here).
bool PairSumUnsortedArray(int arr[],int k)
{
    unordered_set<int>s;
    for(int i=0;i<9;i++)
    {
        int temp=k-arr[i];
        if(s.find(temp)!=s.end())
            return true;
        s.insert(arr[i]);
    }
    return false;

}      
int main()
{
    int arr[9]={1,2,5,6,19,7,9,11,14};
    if(PairSumUnsortedArray(arr,18))
        cout<<"Yes";
    else
        cout<<"No";
}

