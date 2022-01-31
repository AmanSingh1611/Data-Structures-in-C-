int maxMoneyLooted(int *arr, int n)
{
	//Write your code here
    int *dp= new int [n];
    dp[0]=arr[0];
    dp[1]=max(arr[1],arr[0]);
    for( int i=2;i<n;i++){
        dp[i]=max(arr[i]+dp[i-2],dp[i-1]);
    }return dp[n-1];
}