/*A thief robbing a store can carry a maximal weight of W into his knapsack. 
There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' 
What would be the maximum value V, that the thief can steal?
*/
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    int dp[maxWeight+1]={0};
    
    for(int i=0;i<n;i++){
        
        for(int j=maxWeight;j>=weights[i];j--){
            
            dp[j]=max(dp[j],values[i]+dp[j-weights[i]]);
        }
    }
    return dp[maxWeight];
}