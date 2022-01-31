#include <stack>
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.size()<=1){
        return;
    }else{
        int ans=input.top();
        input.pop();
        reverseStack(input,extra);
        while(!input.empty()){
            int k=input.top();
            extra.push(k);
            input.pop();  
        }input.push(ans);
        while(!extra.empty()){
            int k=extra.top();
            input.push(k);
            extra.pop();
        }
    }
    
}