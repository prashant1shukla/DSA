#include<bits/stdc++.h>
using namespace std;
/*What does Max area of histogram means?
Histogram is nothing but a bar graph, hence are required to tell the maximum possible of area of reactangle which 
can be formed inside the histogram. We are given an array which has the heights of the each bar of a histogram. */

/*Approach:
We should find the NSL and NSR for each elements in an array. OK satisfactory!
Then, the width =index of(NSR)-index of(NSR)-1;
Height is know to us= arr[i];
area=width*height;
(output the maximum) */

/*For each NSR and NSL we will be requiring 2 function that will return indexes
And each function will having stack<pair<int,int>>s */

/*also for NSL if(s.size()==0)vleft.push_back(-1)         
for NSR if(s.size()==0)vleft.push_back(right_most_index(=or the size_of_araay))*/
vector<int> NSL_index(int arr[],int n)
{
    int pseudo_index=-1;
    vector<int>v;
    stack<pair<int,int>>s;
    //int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
            v.push_back(pseudo_index);
        else if(s.size()>0 && s.top().first<arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
                v.push_back(pseudo_index);
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    return v;
}
vector<int> NSR_index(int arr[], int n)
{
    int pseudo_index=n;
    vector<int>v;
    stack<pair<int,int>>s;
    //int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n-1;i>=0;i--)
    {
        if(s.size()==0)
            v.push_back(pseudo_index);
        else if(s.size()>0 && s.top().first<arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first>=arr[i])
        {
            while(s.size()>0 && s.top().first>=arr[i])
            {
                s.pop();
            }
            if(s.size()==0)
                v.push_back(pseudo_index);
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i],i});
    }
    reverse(v.begin(),v.end());
    return v;  
}
int main()
{
    int arr[]={6,2,5,4,5,1,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>left_index;
    left_index=NSL_index(arr,n);
    vector<int>right_index;
    right_index=NSR_index(arr,n);
    vector<int>width;
    for(int i=0;i<n;i++)
    {
        int x=right_index[i]-left_index[i]-1;
        width.push_back(x);        
    }
  
    vector<int>area;
    for(int i=0;i<n;i++)
    {
        int x=width[i]*arr[i];   //arr==height
        area.push_back(x);
    }
    cout<<*max_element(area.begin(),area.end())<<endl;
}