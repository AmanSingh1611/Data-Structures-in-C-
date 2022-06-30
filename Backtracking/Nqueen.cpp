#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<vector<int>> &arr,int row,int col,int n){
    for(int i=0;i<=row;i++){
        if(arr[i][col]==1){
            return false;
        }
    }
    
    for(int i=row,j=col;i>=0&&j<n;i--,j++){
        if(arr[i][j]==1){
            return false;
        }
    }
    
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(arr[i][j]==1){
            return false;
        }
    }
    
    return true;
}
void ok(vector<vector<int>> &arr,int row,int n){
    
    if(row==n){
        for(int ii=0;ii<n;ii++){
            for(int jj=0;jj<n;jj++){
                cout<<arr[ii][jj]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    for(int i=0;i<n;i++){
        if(isvalid(arr,row,i,n)){
            arr[row][i]=1;
            ok(arr,row+1,n);
            arr[row][i]=0;
        }
    }
    
}
int main(){
    
    // write your code here
    int n;
    cin>>n;
    vector<vector<int>> arr(n,vector<int>(n,0));
    ok(arr,0,n);
    return 0;
}