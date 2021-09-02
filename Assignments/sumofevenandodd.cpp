#include <iostream>
using namespace std;
int main(){
    int n,even=0,odd=0,didi=0;
    cin>>n;
    while(n>0){
        didi=n%10;
        if (didi%2==0){
            even+=didi;
        }else{
            odd+=didi;
        }n=n/10;        
    }cout<<even<<" "<<odd;
}