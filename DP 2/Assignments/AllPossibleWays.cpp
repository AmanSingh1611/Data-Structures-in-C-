#include <cmath>
/*
Given two integers a and b. You need to find and return the count of possible ways in which 
we can represent the number a as the sum of unique integers raise to the power b.
For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
10 = 1^2 + 3^2 
*/
int getAllWays(int a, int b,int curr){
    if(a<0){
        return 0;
    }if(a==0){
        return 1;
    }int ans=0;
    for(int i=curr;pow(i,b)<=a;i++){
        ans+=getAllWays(a-pow(i,b),b,i+1);
    }return ans;
}
int getAllWays(int a, int b) {
	// Write your code here
    
    return getAllWays(a,b,1);
    
}