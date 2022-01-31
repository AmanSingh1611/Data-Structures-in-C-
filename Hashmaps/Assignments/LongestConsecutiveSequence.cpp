#include <vector>
#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    vector<int> ans;
    vector<int> ans2;
    unordered_map<int,int> a;
    for(int i=0;i<n;i++)
    {
        a[arr[i]]=1;
    }
    int max=0;
    int k=0;
    
    for(int i=0;i<n;i++)
    {
        int x=arr[i];
        int j=0;
        if(a.count(x-1)>0)
            continue;
        while(a.count(x)>0 )
        {
                
            j++;
            x++;
        }
        if(j>max)
        {  
            max=j;
            k=arr[i];
            //cout<<" j:"<<j<<" k:"<<k<<endl; 
        }   
    }
    
    for(int i=0;i<max;i++)
    {
        ans.push_back(k);
        k++;
    }
    ans2.push_back(ans[0]);
    ans2.push_back(ans[ans.size()-1]);
    return ans2;
}