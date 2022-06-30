#include<bits/stdc++.h>
using namespace std;
int ok(vector<int> arr,int tar){
    int dp[tar+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<arr.size();i++){
        for(int j=tar;j>=arr[i];j--){
            dp[j]+=dp[j-arr[i]];
        }
    }return dp[tar];
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n,tar;
        cin>>n>>tar;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        cout<<ok(arr,tar)<<endl;
    }
    return 0;
}