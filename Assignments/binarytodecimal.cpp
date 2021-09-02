#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long int n,ans=0;
    cin>>n;
    while(n>0){
        ans+=2*pow(2,n%10);
        n=n/10;
    }cout<<ans;
}