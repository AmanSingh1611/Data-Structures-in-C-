#include <iostream>
using namespace std;
int duplicateNumber(int *arr, int size)
{
    //Write your code here
    int i=0,j=0,temp=0;
    bool exist=false;
    for(i=0;i<size;i++){
        temp=arr[i];
        for(j=i+1;j<size;j++){
            if(arr[j]==temp){
                exist=true;
                break;
            }else{
                continue;
            }
        }if(exist){
            return temp;
        }
    }
}