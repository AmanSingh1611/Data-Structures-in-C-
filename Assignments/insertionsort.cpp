#include <bits/stdc++.h>
using namespace std;
void insertionsort(vector<int>& arr,int n){
	for(int i=0;i<n;i++){
		while(arr[i-1]>arr[i] && i>0){
			swap(arr[i-1],arr[i]);
			i--;
		}
	}
}
int main(){
	int n;
    cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	insertionsort(arr,n);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}