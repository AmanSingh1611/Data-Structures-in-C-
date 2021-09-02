#include <climits>
void intersection(int *input1, int *input2, int size1, int size2)
{
    //Write your code here
    int i=0,j=0,temp=0;
    for(i=0;i<size1;i++){
        temp=input1[i];
        for(j=0;j<size2;j++){
            if(temp==input2[j]){
                input2[j]=INT_MIN;
                cout<<temp<<" ";
                break;
            }
        }
    }
}