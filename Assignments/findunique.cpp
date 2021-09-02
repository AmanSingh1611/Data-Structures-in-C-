#include <iostream>
using namespace std;
int findUnique(int *arr, int size){
    int i=0,j=0,temp=0;
    for(i=0;i<size;i++){
        bool exist=false;
        for(j=0;j<size;j++){
            if(i==j){
                continue;
            }if(arr[i]==arr[j]){
                exist=true;
                break;
            }
        }if(!exist){
            return arr[i];
        }
    }
    
}