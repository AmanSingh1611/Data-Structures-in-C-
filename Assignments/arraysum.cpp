#include<iostream>
using namespace std;

#include <cstring>
bool checkPalindrome(char str[]) {
    // Write your code here
    int length = 0;
    for(int i = 0; str[i] != '/0'; i++)
    {
        length++;
    }
    int j = 0;
    int k = strlen(str) - 1;
    int flag = 0;
    while(j < k)
    {
        if(str[j] != str[k])
        {
            flag = 1;
            break;
        }
        j++;
        k--;
    }
    if(flag == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int main(){
    /* Read input as specified in the question.
     * Print output as specified in the question.

     */
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");




    // long int n,i=0,j=0,ans=0;
    // cin>>n;
    // int arr[n];
    // for(j=0;j<n;j++){
    //     cin>>arr[j];
    // }
    // for(i=0;i<n;i++){
    //     ans+=arr[i];
    // }
    // cout<<ans;
}


