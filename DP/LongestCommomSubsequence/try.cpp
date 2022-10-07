#include<bits/stdc++.h> 
using namespace std; 
vector<int> getQueryResults(int N,int queries[][3])
{     
    int n=2;     
    vector<int> answer;      
    vector<int> goodArray;     
    while(N>0){         
        int l=log2(N);         
        int val=pow(2,l);         
        goodArray.push_back(val);         
        N-=val;              
    }     
    reverse(goodArray.begin(),goodArray.end());      
    for(int i=0;i<n;i++){         
        int l=queries[i][0],r=queries[i][1],m=queries[i][2];         
        int product=1;         
        for(int j=l-1;j<r;j++){             
            product*=goodArray[j];         
        }         
        answer.push_back(product%m);     
    }     
    return answer; 
} 
int main() {     
int queries[2][3]={{1,2,1009},{3,3,5}};     
vector<int> ans=getQueryResults(26,queries);     
for(auto a:ans{         
    cout<<a<<" ";     
}     
    return 0; 
}
