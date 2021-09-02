#include <iostream>
using namespace std;
int min(long long int a,long long int b){
    if(a>b){
        return b;
    }return a;
}
int transportation(int arr[],long long int n,long long int target){
    long long int ans1=0,ans2=0,e1=0,e2=0;
    for(long long int i=target-1;i>=0;i--){
        if(arr[i]==1){
            e1=1;
            break;
        }else{
            ans1++;
        }
    }for(long long int i=target-1;i<n;i++){
        if(arr[i]==2){
            e2=1;
            break;
        }else{
            ans2++;
        }
    }if(e1 && e2){
        return min(ans1,ans2);
    }else if(e1){
        return ans1;
    }else if(e2){
        return ans2;
    }else{
        return -1;
    }
}
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n,m;
        cin>>n>>m;
        int arr[n];
        int brr[m];
        for(long long int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(long long int i=0;i<m;i++){
            cin>>brr[i];
        }for(long long int j=0;j<m;j++){
            cout<<transportation(arr,n,brr[j])<<" ";
        }
        cout<<endl;
    }
}