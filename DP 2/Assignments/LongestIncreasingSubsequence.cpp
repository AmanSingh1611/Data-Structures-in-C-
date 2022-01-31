/*
Given an array with N elements, 
you need to find the length of the longest subsequence in the given array such that
all elements of the subsequence are sorted in strictly increasing order.
*/
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int* dp=new int [n];
    dp[0]=1;
    for(int i=1;i<n;i++){
        dp[i]=1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i]){
                continue;
            }
            int a=dp[j]+1;
            dp[i]=max(dp[i],a);
        }
    }int ans=0;
    for(int i=0;i<n;i++){
        if(ans<dp[i]){
            ans=dp[i];
        }
    }delete [] dp;
    return ans;
}