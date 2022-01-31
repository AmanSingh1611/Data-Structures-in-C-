#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int good(vector<int> arr,int q){
    int curr=arr.size()-1;
    vector<int> dp(arr.size(),0);
    sort(arr.begin(),arr.end(),greater<int>());
    if(arr[0]>=q){
        dp[0]=1;
    }
    for(int i=1;i<arr.size();i++){
        if(curr<=i){
            return dp[i-1];
        }if(arr[i]>=q){
            dp[i]=1+dp[i-1];
        }else{
            if(arr[i]+curr-i>=q){
                dp[i]=1+dp[i-1];
                curr=curr-q+arr[i];
            }
        }
    }
}
int main(){
    vector<int> temp={21,10,9,8,5};
    cout<<good(temp,15);
}
