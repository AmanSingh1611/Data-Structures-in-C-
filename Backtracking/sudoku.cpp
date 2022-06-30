#include<bits/stdc++.h>
using namespace std;
bool valid(vector<vector<int>> &arr,int row,int col,int num){
    for(int i=0;i<9;i++){
        if(arr[i][col]==num||arr[row][i]==num){
            return false;
        }if(arr[i/3+3*(row/3)][i%3+3*(col/3)]==num){
            return false;
        }
    }return true;
}
bool ok(vector<vector<int>> &arr){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]==0){
                for(int num=1;num<=9;num++){
                    if(valid(arr,i,j,num)){
                        arr[i][j]=num;
                        if(ok(arr)){
                            return true;
                        }else{
                            arr[i][j]=0;
                        }
                    }
                }return false;
            }
        }
    }return true;
}

int main(){
    
    // write your code here
    vector<vector<int>> arr(9,vector<int>(9,0));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
        }
    }
    ok(arr)?cout<<"true":cout<<"false";
    return 0;
}