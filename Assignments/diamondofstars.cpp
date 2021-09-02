#include <iostream>
using namespace std;
int main(){
    int i,j,n1,n2,n;
    cin>>n;
    n1=(n+1)/2;
    n2=n-n1;
    for(i=1;i<=n1;i++){
        for(j=1;j<=n1-i;j++){
            cout<<" ";
        }for(j=1;j<=(2*i-1);j++){
            cout<<"*";
        }cout<<endl;
    }for(i=1;i<=n2;i++){
        for(j=1;j<=i;j++){
            cout<<" ";
        }for(j=1;j<=(n-2*i);j++){
            cout<<"*";
        }cout<<endl;
    }
}