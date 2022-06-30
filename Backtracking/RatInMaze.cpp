/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;
void ok(vector<vector<int>> &arr,int row,int col,vector<vector<int>> &dp,int n){

    if(row==n-1 && col==n-1){
        if(arr[row][col]==1){
            dp[row][col]=1;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<dp[i][j]<<" ";
                }
            }cout<<endl;
        }
        return;
    }

    if(row>=n || col>=n || row<0 || col<0 || arr[row][col]!=1 || dp[row][col]==1){
        return;
    }

    dp[row][col]=1;


    ok(arr,row+1,col,dp,n);
    ok(arr,row,col+1,dp,n);
    ok(arr,row-1,col,dp,n);
    ok(arr,row,col-1,dp,n);


    dp[row][col]=0;
}
int main() {

    // Write your code here
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    ok(arr,0,0,dp,n);
    return 0;
}
