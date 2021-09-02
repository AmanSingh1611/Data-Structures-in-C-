#include <iostream>
using namespace std;
int main(){
   int n,i,j,k;
   cin>>n;
   for(i=1;i<=n;i++){
      j=i;
      for(k=1;k<=n-i;k++){
         cout<<" ";
      }
      for(k=1;k<=(2*i+1)/2;k++){
         cout<<j;
         j++;
         if(k==(2*i+1)/2){
            j=j-1;
            while(j>i){
               cout<<j-1;
               j--;
            }
         }
      }cout<<endl;
   }
}