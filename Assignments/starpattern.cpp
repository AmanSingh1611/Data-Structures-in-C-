#include <iostream>
using namespace std;
int main(){
    int n,i,j,k=1,b=1;
    cin>>n;
    while(k<=n){
        b=k;
        for(i=1;i<=n-k;i++){
        cout<<" "<<" ";
        }
        for(j=n-k;j<n;j++){
        cout<<b<<" ";
        b=b+1;
        }
        k=k+1;
        cout<<endl;
    }    
}
    