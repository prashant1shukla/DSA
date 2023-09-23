#include<bits/stdc++.h>
using namespace std;
vector<int> rotate(vector<int>&nums,int target) {
    sort(nums.begin(),nums.end());
        vector<int>ans;
        int i=0,j=nums.size()-1;
        while(j>i){
            if(nums[i]+nums[j]==target){
                // cout<<i<<" "<<j<<" ";
                cout<<nums[i]<<" "<<nums[j]<<" ";
                
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
            else if(nums[i]+nums[j]>target)
                j--;
            else
                i++;
        }
        return ans;
}
int main(){
    vector<int>v={3,2,4};
    // for(auto x: v)
    //     cout<<x<<" ";
    // cout<<endl;
    int k=6;
    vector<int>p=rotate(v,k);

    for(auto x: p)
        cout<<x<<" ";
   
} 