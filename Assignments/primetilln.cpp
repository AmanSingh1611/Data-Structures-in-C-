#include <iostream>
using namespace std;

int main(){

    /* Read input as specified in the question.
	 * Print output as specified in the question.
	 */
    int n,j=2,k=2;
    cin>>n;
    while(true){
        if(j>n){
            break;
        }if(k*k<=j){
            if(j%k==0){
                j++;
                k=2;
                continue;
            }else{
                k++;
            }
        }else{
            cout<<j<<endl;
            j++;
            k=2;
            continue;            
        }
    }
  
}


