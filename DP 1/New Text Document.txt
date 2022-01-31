/*Given an integer h, find the possible number of balanced binary trees of height h. 
You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
*/
#include <vector>
#include <cmath>
using namespace std;
int balancedBTs(int n) {
    // Write your code here
    int dp[n+1];
    
    dp[0]=1;
    dp[1]=1;
    int mod = (int) (pow(10,9)+ 7);
    for(int i=2 ;i<=n; i++){
        dp[i]=(int)( ( (long)(dp[i-1])*dp[i-1] )%mod + (2*(long)(dp[i-1])*dp[i-2])%mod  ) % mod;
    }return dp[n];
}