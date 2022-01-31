#include <stack>
bool isBalanced(string expression) 
{
    
    stack<char> s; // Declare Stack
    int i=0;
    for(int i=0;expression[i]!='\0';i++){ // Treverse over the string
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{'){
            s.push(expression[i]); // Push if there is an opening bracket
        }else if(expression[i]==')'||expression[i]=='}'||expression[i]==']'){
            if(s.empty()){
            	return false;
            }if(expression[i]==')' && s.top()=='('){
                s.pop(); // Pop if opening and closing bracket pair is formed
                continue;
            }if(expression[i]=='}' && s.top()=='{'){
                s.pop();
                continue;
            }if(expression[i]==']' && s.top()=='['){
                s.pop();
                continue;
            }else{
                return false;
            }
        }
    }return s.empty(); // return if stack is empty.
}