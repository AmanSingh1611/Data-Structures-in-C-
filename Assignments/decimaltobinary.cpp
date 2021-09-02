#include <iostream>
using namespace std;
int main(){
    int zero=0;
    int one=1;
    int pv=1;
    int ans=0;
    int n;
    cin>>n;
    bool exist=false;
    while(n>0){
        exist=true;
        ans+=(n%2)*pv;
        pv=pv*10;
        n=n/2;
    }if (!exist){
        cout<<0;
    }else{
        cout<<ans;
    }
    
}