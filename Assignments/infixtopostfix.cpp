#include <climits>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
template <typename T>
class Stack{
	T *data;
	int nextIndex;
	int capacity;	

	public :

	Stack() {
		data = new T[4];
		nextIndex = 0;
		capacity = 4;
	}
	// return the number of elements present in my stack
	int size() {
		return nextIndex;
	}

	bool empty() {
		return nextIndex == 0;
	}

	// insert element
	void push(T element) {
		if(nextIndex == capacity) {
			T *newData = new T[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			capacity *= 2;
			delete [] data;
			data = newData;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	// delete element
	void pop() {
		if(empty()) {
			return;	
		}
		nextIndex--;
	}
	T top() {
		if(empty()) {
			cout << "Stack is empty " << endl;
			return 0;	
		}
		return data[nextIndex - 1];
	}
};


int precedece(char x){
	if(x=='^'){
		return 3;
	}
	else if(x=='*' || x=='/'){
		return 2;
	}
	else if(x=='+' || x=='-'){
		return 1;
	}else{
		return -1;
	}
}
string infix_to_postfix(string s){
	Stack<char> crr;
	string ans;
	for(int i=0;i<s.length();i++){
		if((s[i]>='a'&& s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='1' && s[i]<='9')){
			ans+=s[i];
		}else if(s[i]=='('){
			crr.push(s[i]);
		}else if(s[i]==')'){
			while(!crr.empty() && crr.top()!='('){
				ans+=crr.top();
				crr.pop();
			}if(!crr.empty()){
				crr.pop();
			}
		}else{
			while(!crr.empty() && precedece(crr.top())>=precedece(s[i])){
				ans+=crr.top();
				crr.pop();
			}crr.push(s[i]);
		}
	}
	while(!crr.empty()){
		ans+=crr.top();
		crr.pop();
	}return ans;
}
int main(){
	cout<<infix_to_postfix("A*(B+C)/D")<<endl;//TEST CASE 1 
	cout<<infix_to_postfix("a+b*(c^d-e)^(f+g*h)-i")<<endl;//TEST CASE 2 
}