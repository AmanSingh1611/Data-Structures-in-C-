/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int x=0;x<t;x++){
		int n,m,max=0;
		cin>>n>>m;
		int arr[n];
		for(int lo=0;lo<n;lo++){
			cin>>arr[lo];
		}for(int i=0;i<n;i++){
			int count=0;
			for(int j=i;j<n;j++){
				count+=arr[j];
				if(count%m==0 && count>max){
					max=count;
				}
			}
		}int ans=max/m;
		cout<<ans<<endl;
	}
}
