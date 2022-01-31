#include <vector>
#include <climits>
/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices.
In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
*/
int matrixChainMultiplication(vector<vector <int> > &dp,int *p,int s,int e){
    if(e-s==1)
        return 0;
    
    if(dp[s][e])
        return dp[s][e];
    
    int ans=INT_MAX;
    for(int k=s+1;k<e;k++){
        int temp=matrixChainMultiplication(dp,p,s,k)+matrixChainMultiplication(dp,p,k,e)+p[s]*p[k]*p[e];
        ans=min(ans,temp);
    }
    dp[s][e]=ans;
    return ans;
}    
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
     vector <vector <int> > dp(n+1,vector<int>(n+1,0));
    int ans=matrixChainMultiplication(dp,arr,0,n);
    return ans;
}