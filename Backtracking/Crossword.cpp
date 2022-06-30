#include<bits/stdc++.h>
using namespace std;
bool CanPlaceHorizontally(vector<string> &arr,int row,int col,string s){
    if((col>=1 && arr[row][col-1]!='+')||(col+s.length()<10 && arr[row][col+s.length()]!='+')){
        return false;
    }
    
    for(int i=0;i<s.length();i++){
        if(i+col==10){
            return false;
        }
        if(arr[row][col+i]!=s[i] && arr[row][col+i]!='-'){
            return false;
        }
    }
    
    return true;
}


bool CanPlaceVertically(vector<string> &arr,int row,int col,string s){
    if((row>=1 && arr[row-1][col]!='+')||(row+s.length()<10 && arr[row+s.length()][col]!='+')){
        return false;
    }
    
    for(int i=0;i<s.length();i++){
        if(i+row==10){
            return false;
        }
        if(arr[row+i][col]!=s[i] && arr[row+i][col]!='-'){
            return false;
        }
    }
    
    return true;
}


vector<bool> PlaceHorizontally(vector<string> &arr,int row,int col,string s){
    vector<bool> vis(s.length(),false);
    for(int i=col;i<col+s.length();i++){
        if(arr[row][i]=='-'){
            vis[i-col]=true;
        }
        arr[row][i]=s[i-col];
    }return vis;
}


vector<bool> PlaceVertically(vector<string> &arr,int row,int col,string s){
    vector<bool> vis(s.length(),false);
    for(int i=row;i<row+s.length();i++){
        if(arr[i][col]=='-'){
            vis[i-row]=true;
        }
        arr[i][col]=s[i-row];
    }return vis;
}


void UnplaceHorizontally(vector<string> &arr,int row,int col,vector<bool> vis){
    for(int i=0;i<vis.size();i++){
        if(vis[i]){
            arr[row][col+i]='-';
        }
    }
}


void UnplaceVertically(vector<string> &arr,int row,int col,vector<bool> vis){
    for(int i=0;i<vis.size();i++){
        if(vis[i]){
            arr[row+i][col]='-';
        }
    }
}


void ok(vector<string> &arr,vector<string> word,int idx){
    if(idx==word.size()){
        for(int i=0;i<10;i++){
            cout<<arr[i]<<endl;
        }
        return;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]=='-'||arr[i][j]==word[idx][0]){
                if(CanPlaceHorizontally(arr,i,j,word[idx])){
                    vector<bool> vis=PlaceHorizontally(arr,i,j,word[idx]);
                    ok(arr,word,idx+1);
                    UnplaceHorizontally(arr,i,j,vis);
                }
                if(CanPlaceVertically(arr,i,j,word[idx])){
                    vector<bool> vis=PlaceVertically(arr,i,j,word[idx]);
                    ok(arr,word,idx+1);
                    UnplaceVertically(arr,i,j,vis);
                }
            }
        }
    }
}


int main(){
    
    // write your code here
    vector<string> arr(10),word;
    
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    
    string str="",ttl;;
    cin>>ttl;
        
    for(auto it:ttl){
        if(it==';'){
            word.push_back(str);
            str="";
        }else{
            str+=it;
        }
    }
    
    word.push_back(str);
    
    ok(arr,word,0);
    
    return 0;
}