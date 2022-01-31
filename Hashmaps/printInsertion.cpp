#include <unordered_map>
/***************************************************************
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. 
You need to print their intersection; An intersection for this problem can be defined when 
both the arrays/lists contain a particular value or to put it in other words, 
when there is a common value that exists in both the arrays/lists.
****************************************************************/
void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int,int> m1 ;
    
    for(int i=0 ;i<n ;i++)
         m1[arr1[i]]++;
    
    for(int i=0 ;i<m ;i++)
    {
        if(m1[arr2[i]]>0)
        {
            cout<<arr2[i]<<endl;
            m1[arr2[i]]--;  //reduce its occurence by 1;
        }
            
    }
}