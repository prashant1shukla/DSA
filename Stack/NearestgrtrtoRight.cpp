#include<bits/stdc++.h>
using namespace std;
/*we are given an array and we are suppose to print another array which
tells us for each element the first element which is grtr than the current element 
that comes to the right of it. IF it dosn't exsist print -1.*/
int main()
{
    int arr[]={1,3,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;   //it will contain the required ans
    stack<int>s;    //this is the backbone of the code
    
    for(int i=n-1;i>=0;i--)       // 1 3 2 4 <-   start traversing from back side.
    {
        if(s.size()==0)
            v.push_back(-1);
        else if(s.size()>0 && s.top()>arr[i])
            v.push_back(s.top());
        else if(s.size()>0 && s.top()<=arr[i])
        {
            while(s.size()>0 && s.top()<=arr[i])
            {
                s.pop();                    //if this is smaller then all will be smaller(for the left ones)
            }
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(arr[i]);    //if this is bigger then no need to checking smaller hence they are already poped out earlier.
    }
    reverse(v.begin(),v.end());
    for(auto x:v)
        cout<<x<<" ";   //we are pushing, hence we are required to reverse the array for getting the correct sequence.
    cout<<endl;
}
