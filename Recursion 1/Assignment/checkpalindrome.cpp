#include <cstring>
bool good(char arr[],int start,int end){
    if(start>=end){
        return true;
    }if(arr[start]!=arr[end]){
        return false;
    }return good(arr,start+1,end-1);
}
bool checkPalindrome(char input[]) {

    return good(input,0,strlen(input)-1);
}


