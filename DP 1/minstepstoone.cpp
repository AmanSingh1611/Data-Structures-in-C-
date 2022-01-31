#include <climits>
/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1.
You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
*/
int countMinStepsToOne(int n)
{
	//Write your code here
    int a[n+1];
     
    a[1]=0; a[2]=a[3]=1;
    int b,c;
    for(int i=4 ;i<n+1;i++){   
		b=c=INT_MAX;
        if(i%2==0) b=a[i/2];
        if(i%3==0) c=a[i/3];
        a[i]=1+ min(a[i-1] ,min(b,c));
    }return a[n];
}