#include<stack>
int countBracketReversals(string input) {
	// Write your code here
    stack<char> st;
	int l =0;
	int count;
    for(int i=0;input[i]!='\0';i++){
        l++;
    }
	if(l % 2 == 0){
		for(int i = 0; input[i] != 0; i++){
			if(input[i] == '{')
				st.push(input[i]);
			else if(input[i] == '}' && !st.empty()){
				if(st.top() == '{')
			       		st.pop();
				else
					st.push(input[i]);
			}
			else
				st.push(input[i]);	
		}
		count = 0;
		while(!st.empty()){
			char c1 = st.top();
			st.pop();
			char c2 = st.top();
			st.pop();
			if(c1 == c2)
				count++;
			else
				count += 2;
		}
		return count;
	}else{
		return -1;
	}
}