#include<iostream>
using namespace std;

int main(){
    /* Read input as specified in the question.
     * Print output as specified in the question.

     */
    long int n,i=0,j=0,ans=0;
    cin>>n;
    int arr[n];
    for(j=0;j<n;j++){
        cin>>arr[j];
    }
    for(i=0;i<n;i++){
        ans+=arr[i];
    }
    cout<<ans;
}


