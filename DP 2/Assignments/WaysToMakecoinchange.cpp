#include <vector>
/*
For the given infinite supply of coins of each of denominations, 
D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, 
in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.
*/
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
	vector<int> dp(value+1,0);
    dp[0]=1;
    for(int j=0;j<numDenominations;j++){
        for(int i=0;i<=value;i++){
            if(denominations[j]>i){
                continue;
            }else{
                dp[i]=dp[i]+dp[i-denominations[j]];
            }
        }
    }return dp[value];
}