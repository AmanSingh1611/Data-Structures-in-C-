#include <bits/stdc++.h>
using namespace std;
bool ok(vector<vector<char>> &arr,string str,int idx,int row,int col){
    if(idx==str.length()){
        return true;
    }
    
    if(row>=arr.size()||col>=arr[0].size()||row<0||col<0){
        return false;
    }
    
    if(str[idx]!=arr[row][col]){
        return false;
    }
    
    vector<int> di={1,0,1,-1,1,-1,-1,0};
    vector<int> dj={0,1,1,-1,-1,1,0,-1};
    
    char curr=str[idx];
    arr[row][col]='*';
    for(int i=0;i<8;i++){
        bool ans=ok(arr,str,idx+1,row+di[i],col+dj[i]);
        if(ans){
            arr[row][col]=curr;
            return true;
        }
    }
    arr[row][col]=curr;
    return false;
}



int hasPath(vector<vector<char>> arr,int n,int m){
    string str="CODINGNINJA";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==str[0]){
                bool ans=ok(arr,str,0,i,j);
                if(ans){
                    return 1;
                }
            }
        }
    }return 0;
}