#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double hra,da,allow,pf;
    int basic,total;
    char rank;
    cin>>basic>>rank;
    hra=(1.59)*(basic);
    char a='A';
    char b='B';
    if(rank==a){
        allow=1700.0;
    }if(rank==b){
        allow=1500.0;
    }else{
        allow=1300.0;
    }
    total=round(hra)+round(allow);
    cout<<total;

}