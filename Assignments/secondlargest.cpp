#include <iostream>
using namespace std;
int main(){
    int second_largest,largest,nums,i=0,j;
    long int x=-2147483648;
    cin>>nums;
    cin>>second_largest;
    while(i<nums){
        cin>>largest;
        if (largest>=second_largest){
            i++;
            continue;
        }    
        else{
            j=largest;
            largest=second_largest;
            second_largest=j;
        }
        i++;
    }if(nums==0 || nums==1 || largest==second_largest){
        cout<<x;
    }else{
        cout<<second_largest;
    }
}    