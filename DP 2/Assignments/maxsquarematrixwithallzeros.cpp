/*
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. 
You need to return the size of the square matrix with all 0s.
*/
int findMaxSquareWithAllZeros(int **arr, int n, int m)
{
	//Write your code here
    if(n==0 && m==0){
        return 0;
    }
    int dp[n][m]={0};
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i][0]=(arr[i][0])?0:1;
        ans=max(ans,dp[i][0]);
    }
    for(int i=0;i<m;i++){
        dp[0][i]=(arr[0][i])?0:1;
        ans=max(ans,dp[0][i]);
    }for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            
            if(arr[i][j]==1)
                dp[i][j]=0;
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            ans=max(ans,dp[i][j]);
        }
    }return ans;
}