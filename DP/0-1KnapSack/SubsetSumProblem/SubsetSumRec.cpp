int n,m;
vector<vector<int>> dp(n,vector<int>(m,-1));
int LCS(string s1, string s2, int ind1, int ind2){
    if(ind1==-1 || ind2==-1){
        return 0;
    }
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][]
    }
}