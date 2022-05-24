#include<bits/stdc++.h>
using namespace std;
/*What is STACK-SPAN?
Stock Span​ is the number of consecutive days (before a specific day) when 
the price of the stock was less than or equal to the price on this specific day.*/

/*When we analyse the meaning of the question we came through:
It is nothing but we need to find the nearest greater element ot the left of it.
PLUS: we need to count the number of day hence we need indexing as well*/
int main()
{
    int arr[]={100,80,60,70,60,75,85};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;          // here we are only storing the indexes initially ..then we will subtract each indexes with the current value of array.
    stack<pair<int,int>>s;   
    
    for(int i=0;i<n;i++)       // ->100,80,60,70,60,75,85    start traversing from front side.
    {
        if(s.size()==0)
            v.push_back(-1);
        else if(s.size()>0 && s.top().first>arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first<=arr[i])
        {
            while(s.size()>0 && s.top().first<=arr[i])
            {
                s.pop();                    //if this is smaller then all will be smaller(for the left ones)
            }
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i],i});    //if this is bigger then no need to checking smaller hence they are already poped out earlier.
    }
    /*till here :
    arr[]=100,80,60,70,60 75,85
    v    = -1  0  1  1  3  1 0
    we need distances/count of days: v[i]=i-v[i];  (v[i] has indexes)
    v    = 1  1  1  2  1   4  6  */

    for(int i=0;i<n;i++)
        v[i]=i-v[i];
    
    for(auto x:v)
        cout<<x<<" ";   //1 1 1 2 1 4 6 
    cout<<endl;

    
}