#include <vector>
#include <cstring>
int eD(vector < vector <int> > &dp,string s1,string s2){
    
    if(s1.size()==0)
        return s2.size();
    if(s2.size()==0)
        return s1.size();
    
    if(dp[s1.size()][s2.size()] >-1)
        return dp[s1.size()][s2.size()];
    
    int ans;
    if(s1[0]==s2[0])
        ans=eD(dp,s1.substr(1),s2.substr(1));
    
    else{
        int optiondel=1+eD(dp,s1.substr(1),s2);
        int optionins=1+eD(dp,s1,s2.substr(1));
        int optionrep=1+eD(dp,s1.substr(1),s2.substr(1));
        
        ans=min(optiondel,min(optionins,optionrep));
    }
    dp[s1.size()][s2.size()]=ans;
    return ans;
    
}
int editDistance(string s1, string s2) {
	// Write your code here
    int n=s1.size();
    int m=s2.size();
    vector < vector <int> > dp(n+1,vector<int>(m+1,-1));
    
    int ans=eD(dp,s1,s2);
    return ans;
}