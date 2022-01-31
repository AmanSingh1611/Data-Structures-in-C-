#include <string>
#include <vector>
/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, 
which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
*/
int solve(string s, string v,vector<vector<int>> &dp) {
    if(s.size()==0){
        return 1550;
    }
    if(v.size()==0){
        return 1;
    }if(dp[s.size()][v.size()]){
        return dp[s.size()][v.size()];
    }
    int i;
    for(i=0;i<v.size();i++){
        if(v[i]==s[0]){
            break;
        }
    }        
    if(i==v.size()){
        return 1;
    }
    int ans2= solve(s.substr(1),v,dp);
    int ans1= 1+solve(s.substr(1),v.substr(i+1),dp);
    int ans=min(ans2,ans1);
    dp[s.size()][v.size()]=min(ans2,ans1);
    return ans;
}
int solve(string s, string v) {
    // Write your code here
    vector<vector<int>> dp(s.size()+1,vector<int>(v.size()+1,0));
    return solve(s,v,dp);
    
}